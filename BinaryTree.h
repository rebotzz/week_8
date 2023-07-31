#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��������ʵ�ֶ�����
// ��������ȫ������������������,
// ���Ƿ���ȫ���������ڿռ��˷ѵ�����;
// ����������������;
//

typedef char BTDataType;
//���ڵ�
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _leftChird;
	struct BinaryTreeNode* _rightChird;
}BTnode;

//��������������ɾ����ô�����,����֮��ƽ�����������ѧϰ
////��ʼ��
//void BinTreeInit();
////����
//void BinTreePush();
////����
////����

//�ڵ㴴��(��ʱ)
BTnode* BTNodeCreate(BTDataType x);
//����������
//ǰ�����
void PrevOrder(BTnode* root);
//�������
void InOrder(BTnode* root);
//�������
void PostOrder(BTnode* root);
//�������ܽڵ�ͳ��
//void BTNodeCount(BTnode* root,int* pcount);//2.0
int BTNodeCount(BTnode* root);//1.0	3.0
//Ҷ�ڵ���ͳ��
int BTNodeLeafCount(BTnode* root);
//����������
int BinTreeDepth(BTnode* root);
