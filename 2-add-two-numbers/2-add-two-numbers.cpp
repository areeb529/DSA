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
    ListNode* reverseLL(ListNode*head){
        if(head==NULL||head->next==NULL)return head;
        ListNode*newHead=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cur=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*tail=dummy;
        ListNode*h1=l1;
        ListNode*h2=l2;
        while(h1||h2||cur){
            int x=0,y=0;
            if(h1)x=h1->val;
            if(h2)y=h2->val;
            int num=x+y+cur;
            if(num>=10)cur=1;
            else cur=0;
            num=num%10;
            tail->next=new ListNode(num);
            tail=tail->next;
            if(h1)h1=h1->next;
            if(h2)h2=h2->next;
        }
        ListNode*head=dummy->next;
        return head;
    }
};