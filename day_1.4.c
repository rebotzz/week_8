#define _CRT_SECURE_NO_WARNINGS


//110. ƽ�������
//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//�����У�һ�ø߶�ƽ�����������Ϊ��
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//1.0   ʱ�临�Ӷ�O(N*N)
    int TreeDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftdepth = TreeDepth(root->left);
    int rightdepth = TreeDepth(root->right);

    return leftdepth > rightdepth ? 1 + leftdepth : 1 + rightdepth;
}


bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }

    int leftdepth = TreeDepth(root->left);
    int rightdepth = TreeDepth(root->right);
    if (leftdepth - rightdepth > 1 || leftdepth - rightdepth < -1)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}



//2.0   �����Ż�,ʱ�临�Ӷ�O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 //�ӳ���
bool _isBalanced(struct TreeNode* root, int* depth)
{
    //�������,�����ظ�����

    //��ײ�,����
    if (root == NULL)
    {
        *depth = 0;
        return true;
    }

    //�ж�ƽ��,������==>�ڵ�ƽ��==>������ƽ��,������ƽ��
    //��Ҫ��������ֵ,�ж��Ƿ�ƽ��� boolֵ,�ж�������ȵ���ֵ
    //ֻҪΪ��,�ͷ���,Ϊ�滹��Ҫ�����ж�,ֱ������
    //���� *depth ���ֵ���õĺ�����
    //����ײ㿪ʼ����
    int leftDepth = 0;
    if (_isBalanced(root->left, &leftDepth) == false)
    {
        return false;
    }

    int rightDepth = 0;
    if (_isBalanced(root->right, &rightDepth) == false)
    {
        return false;
    }

    //�߶Ȳ��ж�,�������ʷ���false ������,�����ݹ�Ҳ���õ����
    int gap = abs(rightDepth - leftDepth);
    if (gap > 1)
    {
        return false;
    }

    //���ظ߶�
    *depth = rightDepth > leftDepth ? rightDepth + 1 : leftDepth + 1;

    return true;
}

bool isBalanced(struct TreeNode* root) {
    //ʱ�临�Ӷ��Ż�ΪO(n)
    int i = 0;
    return _isBalanced(root, &i);

}