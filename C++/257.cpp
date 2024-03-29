/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root, path, str);
        return path;
    }
    
    void helper(TreeNode* root, vector<string>& path, string str){
        if(!root)
            return;
        str = str.empty() ? str + to_string(root->val) : str + "->" + to_string(root->val);
        if(!root->left && !root->right){  //当前节点是叶子节点
            path.push_back(str);
            str = "";
        }
        else{
            helper(root->left, path, str);
            helper(root->right, path, str);
        }
    }
    
private:
    vector<string> path;
    string str;
};