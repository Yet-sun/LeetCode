/*
����һ�� N ������������ڵ�ֵ��ǰ�������

���磬����һ�� 3���� :
             1
          /  |  \
         3   2   4
        / \
       5   6

������ǰ�����: [1,3,5,6,2,4]��
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

//�ݹ�����
class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        // pre(root, ans);
        if(root == nullptr)
            return ans;
        ans.push_back(root->val);
        for(auto node : root->children)
            // pre(node, ans);
            preorder(node);
        return ans;
    }
};

//�����������ݹ飩
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        ans.push_back(root->val);
        for(auto node:root->children){
            for(auto num:preorder(node))
                ans.push_back(num);
        }
        return ans;
    }

};
