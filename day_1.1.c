//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//
////226. ��ת������
////����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
//
///**
// * Definition for a binary tree node.
//
//
// */
//struct TreeNode {
//   int val;
//   struct TreeNode* left;
//   struct TreeNode* right;
//    
//};
//
////����һ:ǰ��
//struct TreeNode* invertTree(struct TreeNode* root) 
//{
//    if (NULL == root)
//    {
//        return NULL;
//    }
//    
//    //��,���ǽ�������,���Ǹı�����ָ���ָ��
//    struct TreeNode* tmp = root->left;
//    root->left = root->right;
//    root->right = tmp;
//    
//    invertTree(root->left);
//    invertTree(root->right);
//    return root;
//}
//
//
////������:����ͺ�����
//struct TreeNode* invertTree(struct TreeNode* root) 
//{
//    if (NULL == root)
//    {
//        return NULL;
//    }
//
//    //��,���ǽ�������,���Ǹı�����ָ���ָ��
//    struct TreeNode* right = root->right;
//    root->right = invertTree(root->left);
//    root->left = invertTree(right);
//
//    return root;
//}