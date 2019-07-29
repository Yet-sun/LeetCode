/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* headNode = new ListNode(0);  //头节点
        headNode->next = head;   //第一个节点
        if(headNode->next == NULL)
            return NULL;
        ListNode* cur = head;
        ListNode* pre = headNode;
        while(cur){
            if(cur->val == val){
                pre->next = cur->next; 
                cur->next = NULL;
                cur = pre->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return headNode->next;
    }
};