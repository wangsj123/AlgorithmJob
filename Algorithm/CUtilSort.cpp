#include "CUtilSort.h"

inline void CUtilSort::_swap(int& l, int& r)
{
	int temp = l;
	l = r;
	r = temp;
}

void CUtilSort::selectSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			_swap(arr[i], arr[minIndex]);
		}
	}
}
