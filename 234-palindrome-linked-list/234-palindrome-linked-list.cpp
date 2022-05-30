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
    ListNode*reverseLL(ListNode*head){
        if(head==NULL||head->next==NULL)return head;
        ListNode*newHead=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return true;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*h1=head,*h2=slow->next;
        slow->next=NULL;
        h2=reverseLL(h2);
        while(h2){
            if(h1->val!=h2->val)return false;
            h1=h1->next;
            h2=h2->next;
        }
        return true;
    }
};