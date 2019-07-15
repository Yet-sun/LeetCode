/*
����һ�� N ������������ڵ�ֵ�ĺ��������

���磬����һ�� 3���� :
             1
          /  |  \
         3   2   4
        / \
       5   6

������������: [5,6,3,2,4,1].
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
