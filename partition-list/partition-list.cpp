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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*l1=NULL;
        ListNode*l2=NULL;
        ListNode*r1=NULL;
        ListNode*r2=NULL;
        ListNode*temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                if(l1==NULL){
                    l1=temp;
                    l2=temp;
                }
                else{
                    l2->next=temp;
                    l2=temp;
                }
            }
            else{
                if(r1==NULL){
                    r1=temp;
                    r2=temp;
                }
                else{
                    r2->next=temp;
                    r2=temp;
                }
            }
            temp=temp->next;
        }
        if(l1==NULL)return r1;
        l2->next=r1;
        if(r2!=NULL)
        r2->next=NULL;
        return l1;
    }
};