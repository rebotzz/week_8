#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

void SelectSort(int* arr, int n)
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

void adjustdown(int* arr, int root, int n)
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
		if (chird < n && arr[chird] > arr[parents])//ע������:chird < n
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

void HeapSort(int* arr, int n)
{
	assert(arr);
	//������,���µ����㷨
	int chird = n - 1;
	int root = (chird - 1) / 2;
	while (root >= 0)
	{
		adjustdown(arr, root--, n);
	}
	//�Ѷ���ĩβ��������
	int size = n - 1;
	while (size > 0)
	{
		swap(&arr[0], &arr[size]);
		adjustdown(arr, 0, size);
		size--;
	}
}

//ð������
void BubbleSort(int* arr, int n)
{
	assert(arr);
	int i = 0;
	int j = 0;
	//���,��������,ֻ�ñ���n - 1��,��n - 1�����������,���һ������Ҳ��������� 
	for (i = 0; i < n - 1; i++)
	{
		//�ڲ�,����Դ��������󽻻�.�Ѿ�����õ�λ�ò��ñȽ�,С������Խ��
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}








void test()
{
	//int arr[] = { 1,9,8,3,4,6,7,2,0 };
	int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	//int arr[] = { 1,2,3,4,5,6,7 };

	int n = sizeof(arr) / sizeof(arr[0]);
	arrayPrintf(arr, n);
	QuickSort(arr, 0, n - 1);
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