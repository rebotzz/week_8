//#define _CRT_SECURE_NO_WARNINGS
//#include "queue.h"
//#include "BinaryTree.h"
//
////�������Ĳ������
////����������ĸ��ڵ� ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��root
//
//
////Definition for a binary tree node.
//// 
////typedef struct TreeNode {
////    int val;
////    struct TreeNode *left;
////    struct TreeNode *right;
////}TreeNode;
//
//////���ڵ�
////typedef struct BinaryTreeNode
////{
////    BTDataType _data;
////    struct BinaryTreeNode* _leftChird;
////    struct BinaryTreeNode* _rightChird;
////}BTnode;
////Return an array of arrays of size *returnSize.
////The sizes of the arrays are returned as *returnColumnSizes array.
////Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//
//
//
//void levelOrder(BTnode* root)
//{
//    //���ö����Ƚ��ȳ����ص�ʵ��
//    if (NULL == root)
//    {
//        return;
//    }
//
//    queue q;
//    QueueInit(&q);
//    QueuePush(&q, root);
//
//    //while (!QueueEmpty(&q))
//    //{
//    //    BTnode* front = QueueFront(&q);
//    //    QueuePop(&q);
//    //    printf("%c ", front->_data);
//	  //	//������ָ�벻���,�������о��ս���Ϊ��.���������ѭ����������.
//    //	//��ȫ�����˶�����
//    //    if (NULL != front->_leftChird)
//    //    {
//    //        QueuePush(&q, front->_leftChird);
//    //    }
//    //    if (NULL != front->_rightChird)
//    //    {
//    //        QueuePush(&q, front->_rightChird);
//    //    }
//    //}
//
//    //2.0   ����push,pop,һ��һ��
//    while (!QueueEmpty(&q))
//    {
//        int n = QueueSize(&q);
//        for (int i = 0; i < n; i++)
//        {
//            BTnode* front = QueueFront(&q);
//            QueuePop(&q);
//            printf("%c ", front->_data);
//            if (NULL != front->_leftChird)
//            {
//                QueuePush(&q, front->_leftChird);
//            }
//            if (NULL != front->_rightChird)
//            {
//                QueuePush(&q, front->_rightChird);
//            }
//        }
//        printf("\n");
//
//    }
//
//}
//
//void test()
//{
//    BTnode* A = BTNodeCreate('a');
//    BTnode* B = BTNodeCreate('b');
//    BTnode* C = BTNodeCreate('c');
//    BTnode* D = BTNodeCreate('d');
//    BTnode* E = BTNodeCreate('e');
//    BTnode* F = BTNodeCreate('f');
//
//
//    A->_leftChird = B;
//    A->_rightChird = C;
//    B->_leftChird = D;
//    B->_rightChird = E;
//    D->_rightChird = F;
//
//    levelOrder(A);
//}
//
//int main()
//{
//    test();
//    return 0;
//}