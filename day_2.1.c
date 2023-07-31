//#define _CRT_SECURE_NO_WARNINGS
//
////oj��Ŀ: ��������ǰ�����     ���������������     �������ĺ������   ��������������
//
//
////��������ǰ�����
////����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
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
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//
//  //�����Ĵ�С,���ڿ�������
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
////�ӳ���
////ԭ���򲻷���ݹ�,�������ʺ�,�����ӳ���
//void _preorderTraversal(struct TreeNode* root, int* arr, int* pi)
//{
//    if (root == NULL)//��������дһ���Ⱥ�,ע��
//    {
//        return;
//    }
//
//    arr[*pi] = root->val;
//    (*pi)++;
//
//    _preorderTraversal(root->left, arr, pi);
//    _preorderTraversal(root->right, arr, pi);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);
//    int* arr = (int*)malloc((*returnSize) * sizeof(int));
//    if (arr == NULL)
//    {
//        exit(-1);
//    }
//
//    int i = 0;
//    _preorderTraversal(root, arr, &i);
//    return arr;
//}
//
//
//
//
////���������������
////����һ���������ĸ��ڵ� root ������ ���� ���� ���� ��
//
//
////�����Ĵ�С,���ڿ�������
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
////�ӳ���
//void _inorderTraversal(struct TreeNode* root, int* arr, int* pi)
//{
//    if (NULL == root)
//    {
//        return;
//    }
//
//    _inorderTraversal(root->left, arr, pi);
//    arr[(*pi)++] = root->val;
//    _inorderTraversal(root->right, arr, pi);
//}
//
//int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);//����Ͳ���,���ؿ�������Ĵ�С
//    int* arr = (int*)malloc((*returnSize) * sizeof(int));
//    if (arr == NULL)
//    {
//        exit(-1);
//    }
//
//    int i = 0;
//    _inorderTraversal(root, arr, &i);
//    return arr;
//}
//
//
//
//
////
////�������ĺ������
////����һ�ö������ĸ��ڵ� root ��������ڵ�ֵ�� ������� ��
//
////�����Ĵ�С,���ڿ�������
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
////�ӳ���
//void _postorderTraversal(struct TreeNode* root, int* arr, int* pi)
//{
//    if (NULL == root)
//    {
//        return;
//    }
//
//    _postorderTraversal(root->left, arr, pi);
//    _postorderTraversal(root->right, arr, pi);
//    arr[(*pi)++] = root->val;
//}
//
//
//
//int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);//����Ͳ���,���ؿ�������Ĵ�С
//    int* arr = (int*)malloc((*returnSize) * sizeof(int));
//    if (arr == NULL)
//    {
//        exit(-1);
//    }
//
//    int i = 0;
//    _postorderTraversal(root, arr, &i);
//    return arr;
//}
//
//
//
////104. ��������������
////����һ�����������ҳ��������ȡ�
////�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
////˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//
//int maxDepth(struct TreeNode* root) {
//    //˼·: 1(������һ��) + ��������������������ߵ����ֵ
//    if (NULL == root)
//    {
//        return 0;
//    }
//
//    int leftDepth = maxDepth(root->left);
//    int rightDepth = maxDepth(root->right);
//
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
//
//
//
////110. ƽ�������
////����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
////�����У�һ�ø߶�ƽ�����������Ϊ��
////һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//
////1.0   ʱ�临�Ӷ�O(N*N)
//int TreeDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    int leftdepth = TreeDepth(root->left);
//    int rightdepth = TreeDepth(root->right);
//
//    return leftdepth > rightdepth ? 1 + leftdepth : 1 + rightdepth;
//}
//
//
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    int leftdepth = TreeDepth(root->left);
//    int rightdepth = TreeDepth(root->right);
//    if (leftdepth - rightdepth > 1 || leftdepth - rightdepth < -1)
//    {
//        return false;
//    }
//
//    return isBalanced(root->left) && isBalanced(root->right);
//}
//
//
////2.0   �㷨�Ż�:ʱ�临�Ӷ��Ż�ΪO(n)
//bool _isBalanced(struct TreeNode* root, int* depth)
//{
//    //�������,�����ظ�����
//
//    //��ײ�,����
//    if (root == NULL)
//    {
//        *depth = 0;
//        return true;
//    }
//
//    //�ж�ƽ��,������==>�ڵ�ƽ��==>������ƽ��,������ƽ��
//    //��Ҫ��������ֵ,�ж��Ƿ�ƽ��� boolֵ,�ж�������ȵ���ֵ
//    //ֻҪΪ��,�ͷ���,Ϊ�滹��Ҫ�����ж�,ֱ������
//    //���� *depth ���ֵ���õĺ�����
//    //����ײ㿪ʼ����
//    int leftDepth = 0;
//    if (_isBalanced(root->left, &leftDepth) == false)
//    {
//        return false;
//    }
//
//    int rightDepth = 0;
//    if (_isBalanced(root->right, &rightDepth) == false)
//    {
//        return false;
//    }
//
//    //�߶Ȳ��ж�,�������ʷ���false ������,�����ݹ�Ҳ���õ����
//    int gap = abs(rightDepth - leftDepth);
//    if (gap > 1)
//    {
//        return false;
//    }
//
//    //���ظ߶�
//    *depth = rightDepth > leftDepth ? rightDepth + 1 : leftDepth + 1;
//
//    return true;
//}
//
//bool isBalanced(struct TreeNode* root) {
//    //ʱ�临�Ӷ��Ż�ΪO(n)
//    int i = 0;
//    return _isBalanced(root, &i);
//
//}