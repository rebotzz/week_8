#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

//�ж�һ�����Ƿ�����ȫ������     ��������k��ڵ����
//����ʵ��

typedef char TreeDataType;
typedef struct TreeNode
{
	TreeDataType val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//�ж�һ�����Ƿ�����ȫ������
bool isCompleteTree(TreeNode* root)
{
    //���ö����Ƚ��ȳ����ص�ʵ��
    if (NULL == root)
    {
        return;
    }

    queue q;
    QueueInit(&q);
    QueuePush(&q, root);

    while (!QueueEmpty(&q))
    {
        //����һ����,�Ͱ����ĺ������,�����Ƚ��ȳ�,��K�����,��K+1�����
        //��ȫ�������� NULL ָ����������,�м�û�б��ָ��
        TreeNode* front = QueueFront(&q);
        if (front == NULL)//������ָ�����ѭ��.�ܵĽ���ѭ��������,���Ƕ�������һ��ȫ�����,ֻ�����ж���ȫ������
        {
            break;
        }
        QueuePop(&q);
        //����������ָ�붼Push������,û���ų� NULL
        QueuePush(&q, front->left);
        QueuePush(&q, front->right);
    }

    //�жϿ�ָ���Ƿ�����
    while (!QueueEmpty(&q))
    {
        if (QueueFront(&q) != NULL)
        {
            return false;
        }
        QueuePop(&q);
    }

    //���ٶ���
    QueueDestroy(&q);
    //������н�����,��û����false,��ô������ȫ������
    return true;
}

TreeNode* TreeNodeCreate(TreeDataType val)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

//�ж�һ�����Ƿ�����ȫ������
void test()
{
    TreeNode* A = TreeNodeCreate('a');
    TreeNode* B = TreeNodeCreate('b');
    TreeNode* C = TreeNodeCreate('c');
    TreeNode* D = TreeNodeCreate('d');
    TreeNode* E = TreeNodeCreate('e');
    //TreeNode* F = TreeNodeCreate('f');


    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    //D->right = F;

    printf("%d\n", isCompleteTree(A));
}

int TreeNodeCountK(TreeNode* root,int k)
{
    //˼·:������,��K��ڵ���� == ������+������ (��K - 1��ڵ����)
    if (root == NULL)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }

    if (k > 0)
    {
        return TreeNodeCountK(root->left, k - 1) + TreeNodeCountK(root->right, k - 1);
    }
}

//��������k��ڵ����
void test2()
{
    TreeNode* A = TreeNodeCreate('a');
    TreeNode* B = TreeNodeCreate('b');
    TreeNode* C = TreeNodeCreate('c');
    TreeNode* D = TreeNodeCreate('d');
    TreeNode* E = TreeNodeCreate('e');
    TreeNode* F = TreeNodeCreate('f');


    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;

    printf("%d \n", TreeNodeCountK(A, 3));
}

int main()
{
    //test();
    test2();

    return 0;
}