/*
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

说明:

树的深度不会超过 1000。
树的节点总不会超过 5000。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int maxdep = 0;

        if(!root)
            return 0;
        if(root->children.size()==0)
            return 1;
        for(int i=0; i<root->children.size(); ++i){
            maxdep = max(maxdep, maxDepth(root->children[i]) + 1);  //递归实现
        }
        return maxdep;
    }
};
