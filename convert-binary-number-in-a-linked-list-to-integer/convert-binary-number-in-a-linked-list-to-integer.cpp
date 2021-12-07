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
        ListNode*ans=reverseLL(head->next);
        ListNode*temp=head->next;
        temp->next=head;
        head->next=NULL;
        return ans;
    }
    int getDecimalValue(ListNode* head) {
        head=reverseLL(head);
        int decimalValue=0;
        ListNode*temp=head;
        int p=1;
        while(temp!=NULL){
            decimalValue+=temp->val*p;
            temp=temp->next;
            p*=2;
        }
        return decimalValue;
    }
};