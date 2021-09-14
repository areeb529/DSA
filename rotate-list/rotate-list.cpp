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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*t=head;
        int l=1;
        while(t->next!=NULL){
            t=t->next;
            l++;
        }
        k=k%l;
        if(k==0)return head;
        ListNode*temp=head;
        for(int i=0;i<l-k-1;i++){
            temp=temp->next;
        }
        t->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
        
        
    }
};