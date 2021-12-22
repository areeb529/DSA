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
    int findLength(ListNode*head){
        ListNode*temp=head;
        int ct=0;
        while(temp){
            ct++;
            temp=temp->next;
        }
        return ct;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)return;
        int length=findLength(head);
        ListNode*temp=head;
        ListNode*prev=NULL;
        ListNode*cur=temp;
        for(int i=0;i<length/2;i++){
            cur=temp;
            while(cur->next){
                cur=cur->next;
                if(prev==NULL)prev=head;
                else prev=prev->next;
            }
            prev->next=NULL;
            cur->next=temp->next;
            temp->next=cur;
            prev=cur;
            temp=cur->next;
        }
        
    }
};