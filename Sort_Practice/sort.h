#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//��ӡ����
void arrayPrintf(int* arr, int n);
//����
void swap(int* p1, int* p2);

//ϣ������
void SelectSort(int* arr, int n);

//������
void HeapSort(int* arr, int n);

//��������
void QuickSort(int* arr, int begin, int end);

//�鲢����
void MergeSort(int* arr, int begin, int end);