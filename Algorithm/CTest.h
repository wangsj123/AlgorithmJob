#pragma once
#include "BigInt.h"
class CTest
{
public:
	bool testSelectSort(int n, int arrMax);
	bool testMergeSort(int n, int arrMax);
	bool testQuickSort(int n, int arrMax);
	bool testShellSort(int n, int arrMax);
	bool testRadixSort(int n, int arrMax);
	bool testSelectSort_BigInt(int n);
	bool testMergeSort_BigInt(int n);
	bool testQuickSort_BigInt(int n);
	bool testShellSort_BigInt(int n);
	bool testRadixSort_BigInt(int n);
private:
	static void generate_arr(int* outArr, int n, const int arrMax);
	static void generate_BigIntarr(BigInt* outArr, int n);

};

