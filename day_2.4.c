//#define _CRT_SECURE_NO_WARNINGS
//
//
////����������	����������
////��һ�����򣬶����û������һ����������ַ�����
////���ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
////�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
////������˶������Ժ��ٶԶ������������������������������
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef char TreeDataType;
//typedef struct TreeNode
//{
//	TreeDataType val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//}TreeNode;
//
////�������ڵ�
//TreeNode* creatTreeNode(TreeDataType val)
//{
//	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
//	if (node == NULL)
//	{
//		perror("malloc");
//		exit(-1);
//	}
//	node->val = val;
//	node->left = node->right = NULL;
//	return node;
//}
//
////���ַ�������������,����
//TreeNode* CreatBinatyTreeByStr(char* str,int* pi)
//{
//	if (*(str + *pi) != '\0')
//	{
//		if (*(str + *pi) == '#')
//		{
//			(*pi)++;
//			return NULL;
//		}
//
//		//���ǿ�,����һ���ڵ�
//		TreeNode* root = creatTreeNode(*(str + (*pi)));
//		(*pi)++;//ÿһ��ݹ��ֵ�����ܻ��,������ָ������ָ��ȷ��;
//		//����
//		root->left = CreatBinatyTreeByStr(str, pi);
//		root->right = CreatBinatyTreeByStr(str, pi);
//
//		return root;
//	}
//	return NULL;
//}
//
//void InOrder(TreeNode* root)
//{
//	if (NULL == root)
//	{
//		return;
//	}
//
//
	//InOrder(root->left);
	//printf("%c ", root->val);
	//InOrder(root->right);
//}
//
////����������
//TreeNode* BinaryFind(TreeNode* root ,TreeDataType val)
//{
//	if (root == NULL)
//	{
//		return NULL;
//	}
//
//	if (root->val == val)
//	{
//		printf("%c\n", root->val);
//		return root;
//	}
//
//	TreeNode* left = BinaryFind(root->left, val);
//	if (left != NULL)
//	{
//		return left;
//	}
//	TreeNode* right = BinaryFind(root->right, val);
//	if (right != NULL)
//	{
//		return right;
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	char str[100] = { 0 };
//	while (scanf("%s", str) != EOF)
//	{
//		//���ַ�������������,����
//		int i = 0;
//		TreeNode* root =  CreatBinatyTreeByStr(str,&i);
//
//		//����������
//		InOrder(root);
//		printf("\n");
//
//		//����
//		TreeNode* p = BinaryFind(root, 'F');
//		printf("%p\n", p);
//		if (p != NULL)
//		{
//			printf("%c\n", p->val);
//		}
//
//	}
//	return 0;
//}