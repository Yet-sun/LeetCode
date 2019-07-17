/*
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false
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
    //递归前序遍历
    bool preorder(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)
            return true;
        if(p!=NULL && q!=NULL && p->val==q->val){
            bool left = preorder(p->left, q->left);
            bool right = preorder(p->right, q->right);
            return left && right;
            //return preorder(p->left, q->left) && preorder(p->right, q->right);
        }
        else
            return false;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p, q);
    }
    
    //官方解法：
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if(p!=NULL && q!=NULL && p->val==q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
    
    //讨论区做法：
    bool isSameTree3(TreeNode* p, TreeNode* q){
        if (p==NULL && q==NULL) return true;
        if(p!=NULL && q!=NULL && p->val==q->val) 
            return isSameTree(p->left, q->left) ? isSameTree(p->right, q->right) : false;
        else 
            return false;
    }
};



