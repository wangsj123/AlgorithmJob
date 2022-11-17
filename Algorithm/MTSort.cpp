
#include <iostream>

#include <thread>
#include <mutex>

#include "CpuTimer.h"

using namespace std;

const long MAX = 1e10L; // max num in array
const int RAND_SEED = 1;

mutex M;  //mutex

//Initialized Data
int* init_arr(int total_num)
{
    srand(RAND_SEED);
    int* arr = (int *)malloc(sizeof(int)*total_num);
    if (arr == NULL){
        cout << "merge malloc failed\n";
        exit(-1);
    }

    for (int i = 0; i < total_num; ++i) {
        arr[i] = rand() % MAX; //random int less than MAX
    }
    return arr;
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
void work(int * start,int* end) {

    //lock_guard<std::mutex> lockGuard(M);  //thread lock and auto unlock

    qsorts(start, end);
    
}

//merge the array
int* merge(int* arr,int seg_num,int total)
{
    int* tmp = (int*)malloc(sizeof(int) * total);
    if (tmp == NULL) {
        cout << "merge malloc failed\n";
        exit(-1);
    }
    int num_in_seg = total / seg_num;

    long* index=new long[seg_num];
    for (int i = 0; i < seg_num; ++i)
    {
        index[i] = i * num_in_seg;
    }

    for (long i = 0; i < total; ++i)
    {
        long min_index = 0;
        long min_num = MAX;
        for (int j = 0; j < seg_num; ++j)
        {
            if ((index[j] < (j + 1) * num_in_seg 
                || (j==seg_num-1)&& index[j] < total)  //对最后一组序列，允许其超过平均大小但是要小于总长度
                && (arr[index[j]] < min_num))
            {
                min_index = j;
                min_num = arr[index[j]];
            }
        }
        tmp[i] = arr[index[min_index]];
        index[min_index]++;
    }
    return tmp;
}


//implement multiple thread sort
int* mul_thread_sort(int* arr,int thread_num,int total_num)
{

    float totalTime = 0.0f;
    CpuTimer cpuTime;
    cpuTime.Reset();

    
    int num_per_thread = total_num / thread_num;  //num of element for each thread
    thread* threads=new thread[thread_num];  //create threads

    printf("Spawning %d threads...\n",thread_num);
    for (int i = 0; i < thread_num; ++i) { // create worker
        if (i < thread_num - 1) {
            threads[i] = thread(work, arr + (i * num_per_thread) , arr + ((i+1)*num_per_thread)-1);
        }
        else {
            threads[i] = thread(work, arr + (i * num_per_thread),arr+total_num-1);  //arrange reset element for the last thread  //对于最后一个线程，将剩余元素全部分配给他
        }
    }

    for (int i = 0; i < thread_num; ++i) {
        threads[i].join();
    }
   
    int* res=merge(arr,thread_num,total_num);

    cpuTime.Tick();
    totalTime = cpuTime.TotalTime();
    printf("Total time: %.7f\n", totalTime);


    
    return res;
}   

// test time used by normal qsort 
void test_qsort(int* arr, int total) { 
        float totalTime = 0.0f;
        CpuTimer cpuTime;
        cpuTime.Reset();

        qsorts(arr, arr + total - 1);
        
        cpuTime.Tick();
        totalTime = cpuTime.TotalTime();
        printf("Total time by qsort: %.7f\n", totalTime);



}

//find descending pair inf ascending sorted array
void find_err(int* arr, int len) {
    for (int i = 0;i < len;i++) {
        if (i > 0 && arr[i - 1] > arr[i]) {
            cout << "wrong:" << arr[i - 1] <<" " << arr[i] << endl;
            getchar();
        }/*else {
            cout << arr[i] << " ";
        }*/
    }
}

void MTSort(int thread_num, int total_num) {
    int* arr=init_arr(total_num); //array inited by random num
    
    int* res = mul_thread_sort(arr,thread_num, total_num);  //multiple thread sort
    find_err(res, total_num);  //detect if any element is less than the former
    //test_qsort(arr, total_num);  
}