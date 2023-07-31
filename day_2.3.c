//#define _CRT_SECURE_NO_WARNINGS
//
//
////OJ��Ŀ: ��ֵ������   �����������  ��ת������   ��ͬ����    ��һ���������� �Գƶ�����   �������ľ���  �ж϶Գƶ�����
////  ���ƶ�����   ���ٸ��Ƶ���(���ٶ�����)
//
//
////965. ��ֵ������
////���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
////ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
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
// //�ӳ���
//bool _isUnivalTree(struct TreeNode* root, int val)
//{
//    //����,��������,��������.
//    //���������,ֱ������;���ؼٽ���;
//    if (NULL == root)
//    {
//        return true;
//    }
//
//    if (_isUnivalTree(root->left, val) == false)
//    {
//        return false;
//    }
//    if (_isUnivalTree(root->right, val) == false)
//    {
//        return false;
//    }
//
//    if (root->val != val)
//    {
//        return false;
//    }
//
//    return true;
//}
//
//bool isUnivalTree(struct TreeNode* root)
//{
//    //ԭ������root->val���ʺϵݹ�,�������Ӻ���;
//    int val = root->val;
//    return _isUnivalTree(root, val);
//}
//
//
//
////�����������
////����һ�ö������ĸ��ڵ㣬���������ȡ�
////�Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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
//
//
//int maxDepth(struct TreeNode* root) {
//    //1 + max(���������,���������)
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
//
////226. ��ת������
////����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
//
////1.0   ����һ:ǰ��
//struct TreeNode* invertTree(struct TreeNode* root) {
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
//
////2.0   ������:����ͺ�����
//struct TreeNode* invertTree(struct TreeNode* root) {
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
//
//
//
////100. ��ͬ����
////�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
////����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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
//
//
//
////572. ��һ����������
////�������ö����� root �� subRoot ��
////���� root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������������ڣ����� true �����򣬷��� false ��
////������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣tree Ҳ���Կ����������һ��������
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//    {
//        return false;
//    }
//
//    //root�������Ƿ���subroot��ͬ
//    if (isSameTree(root, subRoot))
//    {
//        return true;
//    }
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}
//
//
////��ָ Offer 27. �������ľ���
////�����һ������������һ�����������ú���������ľ���
//struct TreeNode* mirrorTree(struct TreeNode* root) {
//    //������ , �������ֱ�ת
//    if (NULL == root)
//    {
//        return NULL;
//    }
//
//    struct TreeNode* preleft = root->left;
//    root->left = mirrorTree(root->right);
//    root->right = mirrorTree(preleft);
//
//    return root;
//}
//
//
////101. �Գƶ�����
////����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
//
//
// //�������ڵ�
//struct TreeNode* creatTreeNode(int val)
//{
//    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node->val = val;
//    node->left = node->right = NULL;
//    return node;
//}
//
//
////���ƶ�����
//struct TreeNode* copyTree(struct TreeNode* root)
//{
//    if (NULL == root)
//    {
//        return NULL;
//    }
//
//    //������ ==>������ڵ� + ���������� + ���������� ,Ȼ�����Ӹ�
//    struct TreeNode* cpyroot = creatTreeNode(root->val);
//    cpyroot->left = copyTree(root->left);
//    cpyroot->right = copyTree(root->right);
//
//    return cpyroot;
//}
//
//// ��ת������
//struct TreeNode* mirrorTree(struct TreeNode* root) {
//    //������ , �������ֱ�ת
//    if (NULL == root)
//    {
//        return NULL;
//    }
//
//    struct TreeNode* preleft = root->left;
//    root->left = mirrorTree(root->right);
//    root->right = mirrorTree(preleft);
//
//    return root;
//}
//
////�ж��Ƿ�����ͬ����
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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
//
////���ٸ��Ƶ���
// //���ٶ�����  1.0 ���ڵ�������,��û���ÿ�,��Ҫ����ÿ�.�ŵ�:��֤�˽ӿڲ�����һ����
//void DestroyTree(struct TreeNode* root)
//{
//    if (NULL == root)
//    {
//        return;
//    }
//
//    DestroyTree(root->left);
//    DestroyTree(root->right);
//    free(root);
//}
//  //2.0   ���ݶ���ָ��,�ÿո��ڵ�
////void DestroyTree(struct TreeNode** root)
////{
////    if (NULL == *root)
////    {
////        return;
////    }
////
////    DestroyTree((*root)->left);
////    DestroyTree((*root)->right);
////    free(*root);
////}
//
//bool isSymmetric(struct TreeNode* root) {
//    //˼·:���Ƹö�����,��ת���ƺ����,�ȽϷ�ת����ԭ�������Ƿ���ͬ,���ٸ��Ƶ���
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    //������
//    struct TreeNode* cpy = copyTree(root);
//
//    //��ת��
//    cpy = mirrorTree(cpy);
//
//    //�Ƚ���
//    bool ret = isSameTree(root, cpy);
//
//    //���ٸ��Ƶ���
//    DestroyTree(cpy);
//	  cpy = NULL;
//    return ret;
//}
//
//
////2.0   �㷨�Ż�: �ռ临�Ӷ��� O(n)���ռ临�Ӷ��ǵݹ����ȣ�Ҳ���Ǹ����߶��й�
//// 
////�ӳ���
//bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
//{
//    //���������� == ����������
//    //���������� == ����������
//    if (left == NULL && right == NULL)
//    {
//        return true;
//    }
//
//    //�ṹ�Գ��ж�
//    if (left == NULL && right != NULL)
//    {
//        return false;
//    }
//    if (left != NULL && right == NULL)
//    {
//        return false;
//    }
//
//    //��ֵ�Գ��ж�
//    if (left->val != right->val)
//    {
//        return false;
//    }
//
//    //ע�����ҵߵ�;�ж��������Ƿ���ͬ��Ӧ��
//    return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    //���������� == ����������
//    //���������� == ����������
//    if (NULL == root)
//    {
//        return true;
//    }
//
//    struct TreeNode* leftTree = root->left;
//    struct TreeNode* rightTree = root->right;
//
//    return _isSymmetric(leftTree, rightTree);
//}