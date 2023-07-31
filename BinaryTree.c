#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"




//�ڵ㴴��(��ʱ)
BTnode* BTNodeCreate(BTDataType x)
{
	BTnode* newnode = (BTnode*)malloc(sizeof(BTnode));
	if (NULL == newnode)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_leftChird = NULL;
	newnode->_rightChird = NULL;
	return newnode;
}

//����������
//ǰ�����
void PrevOrder(BTnode* root)
{
	//��������:���ⲻ���ڲ��,�����ٷֽ�������
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//��	������	������
	printf("%c ", root->_data);
	PrevOrder(root->_leftChird);
	PrevOrder(root->_rightChird);
}
//�������
void InOrder(BTnode* root)
{
	//��������:���ⲻ���ڲ��,�����ٷֽ�������
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//������	��	������
	InOrder(root->_leftChird);//�ǵ��ǵ����Լ�InOrder,����Ū��ǰ�����
	printf("%c ", root->_data);
	InOrder(root->_rightChird);
}
//�������
void PostOrder(BTnode* root)
{
	//��������:���ⲻ���ڲ��,�����ٷֽ�������
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//������	������	��	
	PostOrder(root->_leftChird);
	PostOrder(root->_rightChird);
	printf("%c ", root->_data);
}

//�������ܽڵ�ͳ��
//
//1.0	��̬��������ȫ�ֱ���ʵ��.���ǵڶ���ʹ�����count����ʼ��,�������
//int glo_count;// = 0;//ȫ�ֲ���ʼ��Ĭ��Ϊ0
//int BTNodeCount(BTnode* root)
//{
//	static int count = 0;
//	if (NULL == root)
//	{
//		return 0;
//	}
//	//���ñ���,�ݹ�,�����Լ�
//	count++;
//	BTNodeCount(root->_leftChird);
//	BTNodeCount(root->_rightChird);
//	return count;
//}
//
//2.0	���ô�������
//void BTNodeCount(BTnode* root,int* pcount)
//{
//	if (NULL == root)
//	{
//		return;
//	}
//	//���ñ���,�ݹ�,�����Լ�
//	(*pcount)++;
//	BTNodeCount(root->_leftChird, pcount);
//	BTNodeCount(root->_rightChird, pcount);
//}
//
//3.0	�ݹ�ʵ��(�Ƽ�ʹ��):����1���ڵ� + �������ڵ��� + �������ڵ���
int BTNodeCount(BTnode* root)
{
	if (NULL == root)
	{
		return 0;
	}
	return 1 + BTNodeCount(root->_leftChird) + BTNodeCount(root->_rightChird);
}

//Ҷ�ڵ���ͳ��
int BTNodeLeafCount(BTnode* root)
{
	//˼·:Ҷ�ڵ��� = ������Ҷ + ������Ҷ
	if (root == NULL)
	{
		return 0;
	}
	if (root->_leftChird == NULL && root->_rightChird == NULL)//��Ҷ��
	{
		return 1;
	}
	return BTNodeLeafCount(root->_leftChird) + BTNodeLeafCount(root->_rightChird);
}
//����������
int BinTreeDepth(BTnode* root)
{
	//˼·:��� = 1(����һ��) + �����������һ�������
	if (NULL == root)
	{
		return 0;
	}

	int Ldeep = BinTreeDepth(root->_leftChird);
	int Rdeep = BinTreeDepth(root->_rightChird);
	int deeper = Ldeep > Rdeep ? Ldeep : Rdeep;
	return 1 + deeper;
}