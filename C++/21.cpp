/**
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 示例：
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 */


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

//尾插
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);     //新建一个链表存储归并结果
        ListNode* p = l1;   //指向l1的第一个结点
        ListNode* q = l2;   //指向l2的第一个结点
        ListNode* r = l3;   //指向l3的尾结点，此时也是头结点（此头结点值为NULL）
        
        if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        while(q && p){
            if(p->val < q->val){
                r->next = p;
                r = r->next;
                p = p->next;
            }
            else{
                r->next = q;
                r = r->next;
                q = q->next;
            }
        } 
        //p、q还有剩余节点则直接连接在l3尾结点后面即可
        if(q)
            r->next=q;
        if(p)
            r->next=p;
        return l3->next;
    }
};