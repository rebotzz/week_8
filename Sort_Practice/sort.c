#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//����
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//��ӡ����
void arrayPrintf(int* arr, int n)
{
	assert(arr);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



//�������� ��������
//ǰ��ָ�뷨
int SortPart1(int* arr, int begin, int end)
{
	//ѡ���׼key,��endΪ��׼
	int key = arr[end];
	int prev = begin - 1;
	int cur = begin;
	//Ŀ��:��key��ķ����,��keyС�ķ����
	// [С��key����]  key  [����key����]
	while (cur <= end)
	{
		//cur������keyС��ֵ��ͣ��,prev++,Ȼ�󽻻�cur��prevָ�������
		//cur�����������Ŵ���key������,prev�������С�ڵ���key������
		//���һ�ν���keyIndexָ���key,���Ա�����ɺ�prevָ��������key
		//����������ͷ:    С�ڵ���key...(key)prev  ����key...cur 
		while (arr[cur] > key && cur <= end)
		{
			cur++;
		}
		if (arr[cur] <= key && cur <= end)
		{
			swap(&arr[++prev], &arr[cur]);
			cur++;
		}
	}
	return prev;
}

//��������
void QuickSort(int* arr, int begin ,int end)
{
	assert(arr);
	if (begin >= end)//�����ݹ�����
	{
		return;
	}

	int div = SortPart1(arr, begin ,end);
	//[0, div -1] div [div + 1,end]
	//�ݹ�,�����ָ�������������,�ṹ���ƶ�����,ǰ��
	QuickSort(arr, begin, div - 1);
	QuickSort(arr, div + 1, end);
}