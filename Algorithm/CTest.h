#pragma once
class CTest
{
public:
	bool testSelectSort(int n, int arrMax);
	bool testMergeSort(int n, int arrMax);
	bool testQuickSort(int n, int arrMax);
private:
	static void generate_arr(int* outArr, int n, const int arrMax);
};

