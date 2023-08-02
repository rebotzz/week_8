#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//ջ
// last in first out 
// ����ȳ�,�Ƚ����
////��̬
//#define MAX 100
//typedef struct stack
//{
//	STDatatype _data[MAX];
//	int _size;
//	int _capacity;
//}stack;
//��̬,����
typedef int STDatatype;
typedef struct stack
{
	STDatatype* data;
	int size;
	int capacity;
}stack;

//��ʼ��
void StackInit(stack* ps);

//��ջ
void StackPush(stack* ps, STDatatype x);

//��ջ
void StackPop(stack* ps);
//��ȡ,��Ҫ,��ֱ�Ӳ���ջ,ͨ���ӿں���
STDatatype StackTop(stack* ps);
//����
void StackDestroy(stack* ps);
//�Ƿ�Ϊ��
bool StackEmpty(stack* ps);
//��С
int StackSize(stack* ps);
