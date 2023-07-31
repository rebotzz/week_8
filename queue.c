#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

//��ʼ��
void QueueInit(queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

//���,β��
void QueuePush(queue* pq, QueueDatatype x)
{
	assert(pq);
	queuenode* newnode = (queuenode*)malloc(sizeof(queuenode));
	newnode->_data = x;
	newnode->_next = NULL;

	//�ж�_head�Ƿ�Ϊ��
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}
//��ȡ,front
QueueDatatype QueueFront(queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_head->_data;
}
//��ȡ,back
QueueDatatype QueueBack(queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_tail->_data;
}
//����,ͷɾ
void QueuePop(queue* pq)
{
	assert(pq);
	assert(pq->_head);
	queue* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
}
//����
void QueueDestroy(queue* pq)
{
	assert(pq);
	queuenode* cur = pq->_head;
	while (cur)
	{
		queuenode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
//�п�
bool QueueEmpty(queue* pq)
{
	assert(pq);
	if (pq->_head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//��С
int QueueSize(queue* pq)
{
	assert(pq);
	queuenode* cur = pq->_head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}