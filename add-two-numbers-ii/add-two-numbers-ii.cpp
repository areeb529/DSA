/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*reverse(ListNode*l){
        if(!l||l->next==NULL)return l;
        ListNode*h=reverse(l->next);
        l->next->next=l;
        l->next=NULL;
        return h;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode*t1=l1;
        ListNode*t2=l2;
        int cur=0;
        ListNode*t=NULL;
        ListNode*h=NULL;
        while(t1||t2||cur){
            int v1=0,v2=0;
            if(t1)v1=t1->val;
            if(t2)v2=t2->val;
            int value=v1+v2+cur;
            if(value>9)cur=1;
            else cur=0;
            value%=10;
            if(t){
                t->next=new ListNode(value);
                t=t->next;
            }
            else{
                h=new ListNode(value);
                t=h;
            }
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
        }
        h=reverse(h);
        return h;
    }
};