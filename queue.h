#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//����
// first in first out
// �Ƚ��ȳ�,��β��������,��ͷ������
// ���Զ�ȡ��ͷ�Ͷ�β������
// ���õ�����ʵ��,ͷɾ,β��
// �õ������ṹ��,һ���Ƕ��нڵ�,��һ���Ƕ���ͷ,βָ��
// ����:���ö���ָ��,���÷���ֵ
// ָ���ָ��
//

extern struct TreeNode;
typedef struct TreeNode* QueueDatatype;
//���нڵ�
typedef struct queuenode
{
	//_�������ֽṹ���Ա�����ͱ�ı���
	QueueDatatype* _data;
	struct queue* _next;
}queuenode;
//��������ͷ,βָ��
typedef struct queue
{
	//�е�����ΪFront,Rear
	queuenode* _head;
	queuenode* _tail;
}queue;

//��ʼ��
void QueueInit(queue* pq);

//���,β��
void QueuePush(queue* pq, QueueDatatype x);
//��ȡ,front	
QueueDatatype QueueFront(queue* pq);
//��ȡ,back		Ҳ��������ΪQueueRear
QueueDatatype QueueBack(queue* pq);
//����,ͷɾ
void QueuePop(queue* pq);
//����
void QueueDestroy(queue* pq);
//�п�
bool QueueEmpty(queue* pq);
//��С
int QueueSize(queue* pq);
