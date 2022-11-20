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

int CUtilSort::_preTreatment(int arr[], int n)
{
	int minVal = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < minVal)
		{
			minVal = arr[i];
		}
	}
	if (minVal < 0)
	{
		for (int i = 0; i < n; i++) {
			arr[i] -= minVal;
		}
	}

	return minVal;
}

void CUtilSort::LSDRadixSort(int arr[], int n)
{
	int minVal = _preTreatment(arr, n);
	int maxVal = 0;
	int exp = 1;
	int* buf = new int[n];
	//�ҵ����ֵ��Ϊѭ��ֹͣ�ı�׼ 
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
	}
	//�ӵ�λ����λ���� 	
	while (maxVal >= exp)
	{
		int cnt[10];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			int digit = (arr[i] / exp) % 10;
			cnt[digit]++;
		}
		for (int i = 1; i < 10; i++)
		{
			cnt[i] += cnt[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			int digit = (arr[i] / exp) % 10;
			buf[--cnt[digit]] = arr[i];
		}
		memcpy(arr, buf, sizeof(int) * n);
		exp = exp * 10;
	}
	for (int i = 0; i < n; i++) {
		arr[i] += minVal;
	}
	delete buf;
}



void CUtilSort::selectSortBigInt(BigInt arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (CmpBigInt(arr[j], arr[minIndex]) == -1)
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

void CUtilSort::MergeSortBigInt(BigInt instance[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSortBigInt(instance, low, mid);
		MergeSortBigInt(instance, mid + 1, high);
		MergeBigInt(instance, low, mid, high);
	}
}
void CUtilSort::MergeBigInt(BigInt instance[], int low, int mid, int high)
{
	int left = mid - low + 1;
	int right = high - mid;
	BigInt* leftmarge = new BigInt[left];
	BigInt* rightmarge = new BigInt[right];
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
			if (CmpBigInt(leftmarge[l], rightmarge[r]) == -1)
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

void CUtilSort::QuickSortBigInt(BigInt arr[], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int i = low;
	int j = high;
	BigInt key = arr[high];
	while (true)
	{
		while (CmpBigInt(arr[i], key) != 1)
		{
			i++;
			if (i == high)
			{
				break;
			}
		}
		while (CmpBigInt(arr[j], key) != -1)
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
		_swapbigint(arr[i], arr[j]);
	}
	_swapbigint(arr[i], arr[high]);
	QuickSortBigInt(arr, low, i - 1);
	QuickSortBigInt(arr, i + 1, high);
}

void CUtilSort::ShellSortBigInt(BigInt arr[], int n)
{
	int i, j;
	int step;

	for (step = n / 2; step > 0;step /= 2)/*��������*/
	{
		for (i = step; i < n; i++)
		{
			for (j = i - step; j >= 0; j -= step)
			{
				if (CmpBigInt(arr[j + step], arr[j]) == -1)
				{
					_swapbigint(arr[j + step], arr[j]);
				}
				else
				{
					break;
				}
			}
		}

	}
}

void CUtilSort::RadixSortBigInt(BigInt arr[], int n) {

	int pindex;
	int pmaxl = 0, nmaxl = 0;//��¼�����λ���븺���λ��,ȷ��ѭ������
	//�Ƚ����ݷ�Ϊ���Σ����Ϊ�������ұ�Ϊ����
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (arr[i].Sign == -1)
		{
			if (nmaxl < arr[i].Length)
			{
				nmaxl = arr[i].Length;
			}
			i++;
		}
		while (arr[j].Sign == 1)
		{
			if (pmaxl < arr[j].Length)
			{
				pmaxl = arr[j].Length;
			}
			j--;
		}
		if (i < j)
		{
			_swapbigint(arr[i], arr[j]);
		}
	}
	pindex = i;//��¼��һ��������ʼ��λ��

	BigIntRadix(arr, 0, pindex - 1, nmaxl);
	//��������������
	i = 0, j = pindex - 1;
	while (i < j)
	{
		_swapbigint(arr[i], arr[j]);
		i++;j--;
	}

	BigIntRadix(arr, pindex, n - 1, pmaxl);

}

void CUtilSort::BigIntRadix(BigInt arr[], int low, int high, int loopcount) {
	int n = high - low + 1;
	BigInt* tmp = new BigInt[n];//�洢ÿһ�����������,��Ϊ10�Σ�0-9��
	int* tmpInd = new int[10]; //�洢ÿ��Ͱ��Ԫ����tmp����������λ��
	int radix = 1;
	for (int i = 0; i < loopcount; i++)
	{
		//���ȼ���ÿ��Ͱ�е�Ԫ�ظ���
		//������ʼ��
		for (int j = 0; j < 10; j++)
		{
			tmpInd[j] = 0;
		}
		for (int j = low; j <= high; j++)
		{
			int k = GetIndexNum(arr[j], radix);
			tmpInd[k]++;
		}
		//Ȼ���tmpInd��Ϊ�������ֵ
		tmpInd[0]--;
		for (int j = 1; j < 10; j++)
		{
			tmpInd[j] += tmpInd[j - 1];
		}
		//ѭ��arr�������ݷŵ�tmp
		for (int j = high; j >= low; j--)
		{
			int k = GetIndexNum(arr[j], radix);
			tmp[tmpInd[k]] = arr[j];
			tmpInd[k]--;
		}
		//���¸�ֵarr
		for (int j = low, i = 0; j <= high; j++, i++)
		{
			arr[j] = tmp[i];
		}
		radix++;
	}
	delete[] tmp;
	delete[] tmpInd;

}
