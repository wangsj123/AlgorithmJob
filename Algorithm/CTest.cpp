#include "CTest.h"
#include <iostream>
#include <time.h>
#include "CpuTimer.h"
#include "CUtilSort.h"
#include "BigInt.h"
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
	printf("mergeSort: Array size %d,sort time: %.7f\n", n, totalTime);
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
	printf("quickSort: Array size %d,sort time: %.7f\n", n, totalTime);
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
	printf("shellSort: Array size %d,sort time: %.7f\n", n, totalTime);
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

bool CTest::testRadixSort(int n, int arrMax)
{
	int* iArray = new int[n];
	generate_arr(iArray, n, arrMax);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::RadixSort(iArray, n);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("radixSort: Array size %d,sort time: %.7f\n", n, totalTime);
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

bool CTest::testSelectSort_BigInt(int n)
{
	BigInt* iArray = new BigInt[n];
	generate_BigIntarr(iArray, n);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::selectSortBigInt(iArray, n);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("selectSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%s%s\n", (iArray[i].Sign == 1 ? "" : "-"), iArray[i].Value.c_str());
	}
	printf("\n");
#endif

	delete[] iArray;
	return false;
}

bool CTest::testMergeSort_BigInt(int n)
{
	BigInt* iArray = new BigInt[n];
	generate_BigIntarr(iArray, n);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::MergeSortBigInt(iArray, 0, n - 1);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("mergeSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%s%s\n", (iArray[i].Sign == 1 ? "" : "-"), iArray[i].Value.c_str());
	}
	printf("\n");
#endif
	delete[] iArray;
	return false;
}

bool CTest::testQuickSort_BigInt(int n)
{
	BigInt* iArray = new BigInt[n];
	generate_BigIntarr(iArray, n);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::QuickSortBigInt(iArray, 0, n - 1);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("quickSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%s%s\n", (iArray[i].Sign == 1 ? "" : "-"), iArray[i].Value.c_str());
	}
	printf("\n");
#endif
	delete[] iArray;
	return false;
}

bool CTest::testShellSort_BigInt(int n)
{
	BigInt* iArray = new BigInt[n];
	generate_BigIntarr(iArray, n);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::ShellSortBigInt(iArray, n);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("shellSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%s%s\n", (iArray[i].Sign == 1 ? "" : "-"), iArray[i].Value.c_str());
	}
	printf("\n");
#endif
	delete[] iArray;
	return false;
}

bool CTest::testRadixSort_BigInt(int n)
{
	BigInt* iArray = new BigInt[n];
	generate_BigIntarr(iArray, n);
	float totalTime = 0.0f;
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::RadixSortBigInt(iArray, n);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();
	printf("radixSort: Array size %d,sort time: %.7f\n", n, totalTime);
#if defined _DEBUG
	for (size_t i = 0; i < n; i++)
	{
		printf("%s%s\n", (iArray[i].Sign == 1 ? "" : "-"), iArray[i].Value.c_str());
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

void CTest::generate_BigIntarr(BigInt* outArr, int n)
{
	if (outArr == NULL)
	{
		return;
	}
	srand(unsigned(time(0)));
	for (int i = 0; i < n; i++)
	{
		outArr[i].Sign = (rand() % 2) == 0 ? 1 : -1;
		outArr[i].Length = rand() % 100;
		if (outArr[i].Length == 0)
		{
			outArr[i].Sign = 1;
			outArr[i].Length = 1;
			outArr[i].Value = "0";
		}
		else
		{
			for (int j = 0; j < outArr[i].Length; j++)
			{
				int r = rand() % 10;
				if (j == 0 && r == 0)
				{
					j--;
					continue;
				}
				outArr[i].Value.append(to_string(r));
			}
		}

	}
}
