/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
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
    //普遍做法：三指针遍历
    //思路解析可以看这位兄弟的博客：https://blog.csdn.net/xyh269/article/details/70238501
    ListNode* reverseList1(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    
    //大佬做法
    ListNode* reverseList2(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *p =NULL;
        while(head){
            swap(p,head->next);
            swap(head,p);
        }
        return p; 
    }
};