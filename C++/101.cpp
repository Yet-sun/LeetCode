/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;    //这里根节点为空时算作是对称的
        return cmp(root->left, root->right);
    }
    
    //递归，镜像比较
    bool cmp(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL)
            return true;
        if(l == NULL || r == NULL)
            return false;
        return (l->val == r->val) && cmp(l->right, r->left) && cmp(l->left, r->right);
    }
};