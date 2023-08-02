#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

//��ʼ��
void StackInit(stack* ps)
{
	assert(ps);
	ps->data = (STDatatype*)malloc(4 * sizeof(STDatatype));
	if (ps->data == NULL)
	{
		perror("stackInit");
		exit(-1);
	}
	//ps->size ���Գ�ʼ��Ϊ-1����0;-1ʱ��ʾps->size����ջ��,0ʱ��ʾps->size��ջ������һ��Ԫ��;
	ps->size = 0;
	ps->capacity = 4;
}

//��ջ
void StackPush(stack* ps, STDatatype x)
{
	assert(ps);
	//�����ж�
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		STDatatype* tmp = (STDatatype*)realloc(ps->data,ps->capacity * sizeof(STDatatype));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		else
		{
			ps->data = tmp;
			tmp = NULL;
		}
	}

	//ps->size��ʾջ������һ��
	ps->data[ps->size] = x;
	ps->size++;
}

//��ջ
void StackPop(stack* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}
//��ȡ,��Ҫ��?
STDatatype StackTop(stack* ps)
{
	assert(ps);
	assert(ps->size > 0);
	return ps->data[ps->size - 1];
}
//����
void StackDestroy(stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = ps->size = 0;

}
//�Ƿ�Ϊ��
bool StackEmpty(stack* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//��С
int StackSize(stack* ps)
{
	return ps->size;
}