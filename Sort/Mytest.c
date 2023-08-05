#define _CRT_SECURE_NO_WARNINGS
#include "MySort.h"

void TestInsertSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	InsertSort(arr, n);
	arrayPrintf(arr, n);

}

void TestShellSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	ShellSort(arr, n);
	arrayPrintf(arr, n);
}

void TestSelectSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	SelectSort(arr, n);
	arrayPrintf(arr, n);
}

void TestHeapSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	HeapSort(arr, n);
	arrayPrintf(arr, n);
}

void TestBubbleSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	BubbleSort(arr, n);
	arrayPrintf(arr, n);
}

void TestQuickSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	//int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15 };//,14,13,12,11,10
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };

	//int arr[] = { 0,5,4,1,2,3, };
	//int arr[] = { 5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	QuickSort(arr, 0, n - 1);
	arrayPrintf(arr, n);
}

void TestQuickSortNonR()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	//int arr[] = { 0,5,4,1,2,3 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	QuickSortNonR(arr, 0, n - 1);
	arrayPrintf(arr, n);
}

void TestMergeSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	//int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	int arr[] = {5,4,3,2,1,0 };// 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,
	//int arr[] = { 0,5,4,1,2,3 };
	//int arr[] = { 2,1 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	MergeSort(arr, n);
	arrayPrintf(arr, n);
}





void insertsort1(int* arr, int n)
{
	assert(arr);

	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int key = arr[end + 1];
		//�ҵ���keyС��λ��
		while (arr[end] > key && end >= 0)
		{
			//��key��,һ�κ���,Ϊ����key����λ��
			arr[end + 1] = arr[end];
			end--;
		}
		//��key���뵽end��һλ
		arr[end + 1] = key;
	}
}

void ShellSort1(int* arr, int n)
{
	assert(arr);
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)//��n - gap,����n - 1 -gap
		{
			int end = i;
			int key = arr[end + gap];
			//�ҵ���keyС��λ��
			while (arr[end] > key && end >= 0)
			{
				//��key��,һ�κ���,Ϊ����key����λ��
				arr[end + gap] = arr[end];
				end -= gap;
			}
			//��key���뵽end��һλ
			arr[end + gap] = key;
		}
	}
}

void SelectSort1(int* arr, int n)
{
	assert(arr);
	int end = n - 1;
	while (end > 0)
	{
		int maxIndex = 0;//���ʼ���ԭ�±�λ0,����һ��Ԫ��
		//��������,�ҳ����Ԫ�ص��±�
		for (int i = 0; i <= end; i++)
		{
			if (arr[i] > arr[maxIndex])
			{
				maxIndex = i;
			}
		}
		swap(&arr[maxIndex], &arr[end--]);
	}
}

void adjustdown1(int* arr, int root, int n)
{
	int parents = root;//���ڵ�
	int chird = 2 * parents + 1;//����
	while (parents < n)
	{
		//�����Һ����������
		if (chird + 1 < n && arr[chird + 1] > arr[chird])
		{
			chird++;
		}
		//����ϸ�,С���³�
		if (arr[chird] > arr[parents])
		{
			swap(&arr[chird], &arr[parents]);
			parents = chird;
			chird = 2 * parents + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort1(int* arr,int n)
{
	assert(arr);
	//������,���µ����㷨
	int chird = n - 1;
	int root = (chird - 1) / 2;
	while (root >= 0)
	{
		adjustdown1(arr, root, n);
	}

	//�Ѷ���ĩβ��������
	int size = n - 1;
	while (size > 1)
	{
		swap(&arr[0], &arr[size--]);
		adjustdown1(arr, 0, size + 1);
	}

}

void test()
{
	//int arr[] = { 1,9,8,3,4,6,7,2,0 };
	int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };

	int n = sizeof(arr) / sizeof(arr[0]);
	arrayPrintf(arr, n);
	HeapSort1(arr, n);
	arrayPrintf(arr, n);

}







int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestQuickSortNonR();
	//TestMergeSort();
	test();


	return 0;
}