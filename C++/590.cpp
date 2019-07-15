/*
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :
             1
          /  |  \
         3   2   4
        / \
       5   6

返回其后序遍历: [5,6,3,2,4,1].
*/

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

//递归做法
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root)
            return ans;
        for(auto node : root->children)
            postorder(node);
        ans.push_back(root->val);
        return ans;
    }

private:
    vector<int> ans;
};
