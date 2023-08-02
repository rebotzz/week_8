//#define _CRT_SECURE_NO_WARNINGS
//#include "Sort.h"
//#define DEBUG
////#undef DEBUG
//
////��ӡ����
//void arrayPrintf(int* arr, int n)
//{
//	assert(arr);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//
//
////ֱ�Ӳ�������
//void SortInsert(int* arr, int n)
//{
//#ifdef DEBUG
//	int count = 0;
//#endif // DEBUG
//
//
//	//����
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + 1] = arr[end];
//				end--;
//#ifdef DEBUG
//				count++;
//#endif // DEBUG
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		arr[end + 1] = tmp;
//	}
//
//#ifdef DEBUG
//	printf("%d\n", count);
//#endif // DEBUG
//}
//
//
////��������	ϣ������ѧϰ1.0
//void Sort(int* arr, int n)
//{
//#ifdef DEBUG
//	int count = 0;
//#endif // DEBUG
//
//	int gap = 3;
//
//	//Ԥ����
//	//for (int i = 0; i < n - gap; i += gap)
//	for (int i = 0; i < n - gap; i++)
//	{
//		int end = i;
//
//		int tmp = arr[end + gap];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + gap] = arr[end];
//				end = end - gap;
//#ifdef DEBUG
//				count++;
//#endif // DEBUG
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		arr[end + gap] = tmp;
//	}
//
//	//����
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + 1] = arr[end];
//				end--;
//#ifdef DEBUG
//				count++;
//#endif // DEBUG
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		arr[end + 1] = tmp;
//	}
//#ifdef DEBUG
//	printf("%d\n", count);
//#endif // DEBUG
//}
//
//
//
//
//ϣ������
//void ShellSort(int* arr, int n)
//{
//
//#ifdef DEBUG
//	int count = 0;
//#endif // DEBUG
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;	// +1 ��Ϊ�˱�֤���һ��gap = 1,��һ�ξ���ֱ�Ӳ�����������
//
//		//Ԥ����
//		//for (int i = 0; i < n - gap; i += gap)
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//
//			int tmp = arr[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < arr[end])
//				{
//					arr[end + gap] = arr[end];
//					end = end - gap;
//#ifdef DEBUG
//					count++;
//#endif // DEBUG
//				}
//				else
//				{
//					break;
//				}
//			}
//
//			arr[end + gap] = tmp;
//		}
//#ifdef DEBUG
//		arrayPrintf(arr, n);
//#endif // DEBUG
//
//	}
//
//#ifdef DEBUG
//	printf("%d\n", count);
//#endif // DEBUG
//}
//
//
//
//
//
//
//
//
////����ȡ��
//int GetMid(int* arr, int begin, int end)
//{
//	int left = arr[begin];
//	int right = arr[end];
//	int mid = arr[(begin + end) / 2];
//
//}
//
//
//
//
//
////�������� �������� 3.0����ָ�뷨
//int PartSort3(int* arr, int begin, int end)
//{
//	//����ȡ��
//
//
//	int key = arr[end];
//	int prev = begin - 1;
//	int cur = begin;
//
//	while (cur < end)
//	{
//		//cur�ұ�keyС��,�ҵ����ͣ����;
//		if (cur < end && arr[cur] < key)
//		{
//			//cur�ҵ���,prev++
//			prev++;
//			//����prev��cur;
//			swap(&arr[prev], &arr[cur]);
//		}
//		cur++;
//
//
//	}
//
//	prev++;
//	swap(&arr[prev], &arr[end]);
//
//	return prev;
//}
//
//
////����
//void swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//
////��������
//void QuickSort(int* arr, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int div = PartSort3(arr, begin, end);
//
//	QuickSort(arr, begin, div - 1);
//	QuickSort(arr, div + 1, end);
//}