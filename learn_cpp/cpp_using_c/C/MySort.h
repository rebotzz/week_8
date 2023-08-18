#pragma once
#include <stdio.h>
#include <assert.h>

//��ӡ����
void arrayPrintf(int* arr, int n);
//����
void swap(int* p1, int* p2);

//�Լ�д
// 
//��������	������(�ڴ��ڲ�)
//ֱ�Ӳ�������
void InsertSort(int* arr, int n);
//ϣ������
void ShellSort(int* arr, int n);


//ѡ������	������
//ֱ��ѡ������
void SelectSort(int* arr, int n);
//������
void HeapSort(int* arr, int n);

//��������	������
//ð������
void BubbleSort(int* arr, int n);
//��������
void QuickSort(int* arr, int begin, int end);
//��������(�ǵݹ�)	
void QuickSortNonR(int* arr, int begin, int end);

//�鲢����	������(Ҳ����������),���������,����Ӳ��
void MergeSort(int* arr, int n);
