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

////�鲢�����ӳ���
//void _MergeSort(int* arr,int* tmp, int begin, int end)
//{
//	assert(arr);
//	if (begin >= end)
//	{
//		return;
//	}
//	//begin mid mid+1 end
//	// begin end1 begin1 end
//	//��������ǰ����� ==> ���
//	int mid = (begin + end) / 2;
//	int end1 = mid;
//	int begin1 = mid + 1;
//	_MergeSort(arr,tmp, begin, end1);
//	_MergeSort(arr,tmp, begin1, end);
//
//	//arrayPrintf(arr + begin, end - begin + 1);
//
//	// begin end1 begin1 end
//	//�鲢,����
//	int tbegin = begin;
//	int first = begin;
//	//��������������ѡ����Сֵ�鲢��tmp����
//	while (begin <= end1 && begin1 <= end)
//	{
//		if (arr[begin] < arr[begin1])
//		{
//			tmp[tbegin++] = arr[begin++];
//		}
//		else
//		{
//			tmp[tbegin++] = arr[begin1];
//			begin1++;
//		}
//		//printf("%d->", tmp[tbegin -1]);
//	}
//
//	//������һ�����,��һ�鴦��
//	while (begin <= end1)
//	{
//		tmp[tbegin++] = arr[begin++];
//	}
//	while (begin1 <= end)
//	{
//		tmp[tbegin++] = arr[begin1];
//		begin1++;
//	}
//
//	//��ÿ�ι鲢������ݷŻ�ԭ����
//	int i = first;
//	for (i = first; i <= end; i++)
//	{
//		arr[i] = tmp[i];
//	}
//
//}
//
////�鲢����
//void MergeSort(int* arr,int n)
//{
//	//����ռ�洢�鲢������
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (NULL == tmp)
//	{
//		perror("malloc error");
//		exit(-1);
//	}
//	//1.��� 2.�鲢
//	_MergeSort(arr, tmp, 0, n - 1);
//
//	//������õ�tmp���鿽������arr
//	//memmove(arr, tmp, sizeof(int) * n);
//	//�ͷ�tmp
//	free(tmp);
//	tmp = NULL;
//}


//�����Ż� 1.0
//�鲢�����ӳ���
void _MergeSort(int* arr, int* tmp, int begin, int end)
{
	assert(arr);
	if (begin >= end)  //�����ݹ�����
	{
		return;
	}

	//��������ǰ����� ==> ���
	//[begin end] ==>  [begin1 end1] [begin2 end2]
	int begin1 = begin;
	int end1 = (begin + end) / 2;
	int begin2 = end1 + 1;       //Сϸ��:��if (begin >= end)���Ӧ
	int end2 = end;
	_MergeSort(arr, tmp, begin1, end1);
	_MergeSort(arr, tmp, begin2, end2);

	//[begin1 end1] [begin2 end2]
	//�鲢+����
	int tmpbegin = begin;
	//��������������ѡ����Сֵ�鲢��tmp����
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[tmpbegin++] = arr[begin1++];
		}
		else
		{
			tmp[tmpbegin++] = arr[begin2++];
		}
	}

	//������һ�����,��һ�鴦��
	while (begin1 <= end1)
	{
		tmp[tmpbegin++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[tmpbegin++] = arr[begin2++];
	}

	//������õ�tmp���鿽������arr
	// ��Ϊ�ݹ��ֺ���߼���Ԫ�� ==> ��arr����������������г�ȡ�����������η���tmp����
	// ����������������arr�����������鲢��tmp�Ļ���
	//��ÿ�ι鲢������ݷŻ�ԭ���� ==> �ؼ�:������!
	int i = begin;
	for (i = begin; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}

//�鲢����
void MergeSort(int* arr, int begin, int end)
{
	//��ʱ�ռ�洢�鲢������
	int* tmp = (int*)malloc(sizeof(int) * (end - begin + 1));
	if (NULL == tmp)
	{
		perror("malloc error");
		exit(-1);
	}

	//1.��� 2.�鲢
	//begin end
	_MergeSort(arr, tmp, begin, end);

	//�ͷ�tmp
	free(tmp);
	tmp = NULL;
}



void test()
{
	//int arr[] = { 1,9,8,3,4,6,7,2,0 };
	int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	//int arr[] = { 1,2,3,4,5,6,7 };
	//int arr[] = { 4,3,2,1 };

	int n = sizeof(arr) / sizeof(arr[0]);
	arrayPrintf(arr, n);
	MergeSort(arr, 0, n - 1);
	arrayPrintf(arr, n);

}







//int main()
//{
//	//TestInsertSort();
//	//TestShellSort();
//	//TestSelectSort();
//	//TestHeapSort();
//	//TestBubbleSort();
//	//TestQuickSort();
//	//TestQuickSortNonR();
//	//TestMergeSort();
//	//test();
//
//
//	return 0;
//}