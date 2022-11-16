#pragma once
#include "BigInt.h"
class CUtilSort
{
private:
	static void Merge(int instance[], int low, int mid, int high);
	static void MergeBigInt(BigInt instance[], int low, int mid, int high);
public:
	inline static void _swapbigint(BigInt& l, BigInt& r);
	/**********************************************************************************
	*
	* function _swap
	* Given two integer, exchange their value.
	*
	**********************************************************************************/
	inline static void _swap(int& l, int& r);

	/**********************************************************************************
	*
	* function selectSort
	* input arr[]: iteger array
	* input n: array elements number
	* output arr[]: arrays sorted from small to large
	*
	**********************************************************************************/
	static void selectSort(int arr[], int n);

	/**********************************************************************************
	*
	* function MergeSort
	* input arr[]:  unordered iteger array
	* input low: index of the array left
	* input high: index of the array right
	* output arr[]: arrays sorted from small to large
	*
	**********************************************************************************/
	static void MergeSort(int arr[], int low, int high);
	static void QuickSort(int arr[], int low, int high);
	static void ShellSort(int arr[], int n);
	static void RadixSort(int arr[], int n);

	static void selectSortBigInt(BigInt arr[], int n);
	static void MergeSortBigInt(BigInt arr[], int low, int high);
	static void QuickSortBigInt(BigInt arr[], int low, int high);
	static void ShellSortBigInt(BigInt arr[], int n);
};

