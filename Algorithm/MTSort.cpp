
#include <iostream>

#include <thread>
#include <mutex>

#include "CpuTimer.h"

using namespace std;

const long MAX = 1e8L; // max num in array
const long long MAX_NUM = 1e7L;  // num of element to sort
const int THREAD = 25;  //num of thread
const int thread_num = MAX_NUM / THREAD;  //num of element for each thread

int num[MAX_NUM];
int tmp_num[MAX_NUM];

mutex M;  //mutex

//Initialized Data
void init()
{
    srand(1);
    for (int i = 0; i < MAX_NUM; ++i) {
        num[i] = rand() % MAX; //random int less than MAX
    }
}

//Quick sort function
void qsorts(int* start, int* end) {
    int nums = end - start;
    if (nums > 0) {
        int flag = start[0];
        int i = 0;
        int j = nums;
        while (i < j) {
            while (j > i && start[j] > flag) {
                --j;
            }
            start[i] = start[j];
            while (i < j && start[i] <= flag) {
                ++i;
            }
            start[j] = start[i];
        }
        start[i] = flag;

        qsorts(start, start + i - 1);
        qsorts(start + i + 1, end);
    }
}

//sort worker
void work(long ind) {
    long index = ind;
    lock_guard<std::mutex> lockGuard(M);  //thread lock and auto unlock

    qsorts(num + index, num + index + thread_num - 1);
   
}

//merge the array
void merge()
{
    long index[THREAD];
    for (int i = 0; i < THREAD; ++i)
    {
        index[i] = i * thread_num;
    }

    for (long i = 0; i < MAX_NUM; ++i)
    {
        long min_index;
        long min_num = MAX;
        for (int j = 0; j < THREAD; ++j)
        {
            if ((index[j] < (j + 1) * thread_num)
                && (num[index[j]] < min_num))
            {
                min_index = j;
                min_num = num[index[j]];
            }
        }
        tmp_num[i] = num[index[min_index]];
        index[min_index]++;
    }
}



void sort()
{
    init(); //array inited by random num

    printf("length of array:%d\n", MAX_NUM);

    float totalTime = 0.0f;
    CpuTimer cpuTime;
    cpuTime.Reset();
    
    

    thread threads[THREAD];  //create threads

    cout << "Spawning  threads...\n";
    for (int i = 0; i < THREAD; ++i) {
        threads[i] = thread(work, (i * thread_num)); // create worker
    }

    for (auto& thread : threads) {
        thread.join();
    }


    merge();

    cpuTime.Tick();
    totalTime = cpuTime.TotalTime();
    printf("Total time: %.7f\n", totalTime);
 
    
    //for (int i = 0;i < MAX_NUM;i++)cout << num[i] << " ";
}