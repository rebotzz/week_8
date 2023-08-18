#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//��
//С��,���
// ���µ����㷨,���ϵ����㷨,�ݹ�
// ��ȫ������,����������,������ֵ����֧��������ʵ��ص�
// ������,��ֵ�ƶ������,������,��������,ѡ���µ���ֵ,�ظ�;
// TopK����,����һ��K�����Ķ�.����Сֵ�ͽ������;�����ֵ�ͽ���С��;
// �Ѷ��ǿ��Ź�,��������/С���滻��,����;
//

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;


//�ӿں���
//��ʼ��,�������ݵ���,�ݹ����µ����������/С��
void HeapInit(Heap* php, HPDataType* a, int n);
//����,���뵽ĩβ,��Ѷ�����,���µ���
void HeapPush(Heap* php, HPDataType x);
//�����Ѷ�Ԫ��
void HeapPop(Heap* php);
//��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* php);
//����
void HeapDestroy(Heap* php);

//���µ����㷨
void AdjustDown(Heap* php, int n, int root);
//���ϵ����㷨
void AdjustUp(Heap* php, int n, int chird);
//����
void swap(HPDataType* a, HPDataType* b);
//������
void HeapSort(Heap* php);


//����
void print_hello();