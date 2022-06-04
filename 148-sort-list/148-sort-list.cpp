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
    ListNode*mergeSortedLL(ListNode*head1,ListNode*head2){
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        if(head1->val<=head2->val){
            head1->next=mergeSortedLL(head1->next,head2);
            return head1;
        }
        else{
            head2->next=mergeSortedLL(head1,head2->next);
            return head2;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*head1=head;
        ListNode*head2=slow->next;
        slow->next=NULL;
        head1=sortList(head);
        head2=sortList(head2);
        return mergeSortedLL(head1,head2);
    }
};