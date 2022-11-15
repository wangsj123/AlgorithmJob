#include "CTest.h"
#include <iostream>
#include <time.h>
#include "CpuTimer.h"
#include "CUtilSort.h"
using namespace std;
bool CTest::testSelectSort(int n, int arrMax)
{
	int* iArray = new int[n];
	generate_arr(iArray, n, arrMax);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::selectSort(iArray, n);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("selectSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%d,", iArray[i]);
	}
	printf("\n");
#endif

	delete[] iArray;
	return false;
}

bool CTest::testMergeSort(int n, int arrMax)
{
	int* iArray = new int[n];
	generate_arr(iArray, n, arrMax);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::MergeSort(iArray, 0, n - 1);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("selectSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%d,", iArray[i]);
	}
	printf("\n");
#endif
	delete[] iArray;
	return false;
}

bool CTest::testQuickSort(int n, int arrMax)
{
	int* iArray = new int[n];
	generate_arr(iArray, n, arrMax);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::QuickSort(iArray, 0, n - 1);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("selectSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%d,", iArray[i]);
	}
	printf("\n");
#endif
	delete[] iArray;
	return false;
}

bool CTest::testShellSort(int n, int arrMax)
{
	int* iArray = new int[n];
	generate_arr(iArray, n, arrMax);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::ShellSort(iArray, n);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("selectSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%d,", iArray[i]);
	}
	printf("\n");
#endif
	delete[] iArray;
	return false;
}

void CTest::generate_arr(int* outArr, int n, const int arrMax)
{
	if (outArr == NULL)
	{
		return;
	}
	srand(unsigned(time(0)));
	for (int i = 0; i < n; i++)
	{
		int itemp = arrMax < RAND_MAX ? rand() % arrMax : (int)((double)(rand() * arrMax) / RAND_MAX);
		outArr[i] = itemp;
	}
}
