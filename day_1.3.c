//#define _CRT_SECURE_NO_WARNINGS
//
////100. ��ͬ����
////�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
////����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
//
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//    bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//
//    //�ṹ�ж�,����ͬ
//    if (p == NULL && q != NULL)
//    {
//        return false;
//    }
//    if (p != NULL && q == NULL)
//    {
//        return false;
//    }
//
//    //��ֵ�ж�,����ͬ
//    if (p->val != q->val)
//    {
//        return false;
//    }
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//ע��p,q��д��
//}