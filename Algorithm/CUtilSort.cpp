#include "CUtilSort.h"
#include "math.h"
#include "BigInt.h"

inline void CUtilSort::_swap(int& l, int& r)
{
	int temp = l;
	l = r;
	r = temp;
}

inline void CUtilSort::_swapbigint(BigInt& l, BigInt& r)
{
	BigInt temp = l;
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

void CUtilSort::MergeSort(int instance[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(instance, low, mid);
		MergeSort(instance, mid + 1, high);
		Merge(instance, low, mid, high);
	}
}

void CUtilSort::Merge(int instance[], int low, int mid, int high)
{
	int left = mid - low + 1;
	int right = high - mid;
	int* leftmarge = new int[left];
	int* rightmarge = new int[right];
	for (int i = 0; i < left; i++)
	{
		leftmarge[i] = instance[low + i];
	}
	for (int i = 0; i < right; i++)
	{
		rightmarge[i] = instance[mid + 1 + i];
	}

	int l = 0, r = 0;
	for (int i = low; i <= high; i++)
	{
		if (l == left)
		{
			instance[i] = rightmarge[r];
			r++;
		}
		else if (r == right)
		{
			instance[i] = leftmarge[l];
			l++;
		}
		else {
			if (leftmarge[l] < rightmarge[r])
			{
				instance[i] = leftmarge[l];
				l++;
			}
			else
			{
				instance[i] = rightmarge[r];
				r++;
			}
		}
	}
}


void CUtilSort::QuickSort(int arr[], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int i = low;
	int j = high;
	int key = arr[high];
	while (true)
	{
		while (arr[i] <= key)
		{
			i++;
			if (i == high)
			{
				break;
			}
		}
		while (arr[j] >= key)
		{
			j--;
			if (j == low)
			{
				break;
			}
		}
		if (i >= j)
		{
			break;
		}
		_swap(arr[i], arr[j]);
	}
	_swap(arr[i], arr[high]);
	QuickSort(arr, low, i - 1);
	QuickSort(arr, i + 1, high);
}

void CUtilSort::ShellSort(int arr[], int n)
{
	int i, j;
	int step;

	for (step = n / 2; step > 0;step /= 2)/*��������*/
	{
		for (i = step; i < n; i++)
		{
			for (j = i - step; j >= 0; j -= step)
			{
				if (arr[j + step] < arr[j])
				{
					_swap(arr[j + step], arr[j]);
				}
				else
				{
					break;
				}
			}
		}

	}
}

void CUtilSort::RadixSort(int arr[], int n) {

	//��ȡ�����е����ֵ
	int maxarr = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (maxarr < arr[i])
		{
			maxarr = arr[i];
		}
	}
	//�������ֵ�ĳ��ȣ�ȷ��ѭ������
	int p = 1;
	while (maxarr / 10 != 0)
	{
		p++;
		maxarr /= 10;
	}

	int* tmp = new int[n];//�洢ÿһ�����������,��Ϊ10��Ͱ��0-9��
	int* tmpInd = new int[10]; //�洢ÿ��Ͱ��Ԫ����tmp����������λ��
	int radix = 1;
	for (int i = 0; i < p; i++)
	{
		//���ȼ���ÿ��Ͱ�е�Ԫ�ظ���
		//������ʼ��
		for (int j = 0; j < 10; j++)
		{
			tmpInd[j] = 0;
		}
		for (int j = 0; j < n; j++)
		{
			int k = (arr[j] / radix) % 10;
			tmpInd[k]++;
		}
		//Ȼ���tmpInd��Ϊ�������ֵ
		tmpInd[0]--;
		for (int j = 1; j < 10; j++)
		{
			tmpInd[j] += tmpInd[j - 1];
		}
		//ѭ��arr�������ݷŵ�tmp
		for (int j = n - 1; j >= 0; j--)
		{
			int k = (arr[j] / radix) % 10;
			tmp[tmpInd[k]] = arr[j];
			tmpInd[k]--;
		}
		//���¸�ֵarr
		for (int j = 0; j < n; j++)
		{
			arr[j] = tmp[j];
		}
		radix *= 10;
	}
	delete[] tmp;
	delete[] tmpInd;

}

void CUtilSort::selectSortBigInt(BigInt arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (CmpBigInt(arr[j], arr[minIndex]))
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			_swapbigint(arr[i], arr[minIndex]);
		}
	}
}
