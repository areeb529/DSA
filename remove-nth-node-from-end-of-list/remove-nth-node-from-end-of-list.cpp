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
    int length(ListNode* head){
        if(head==NULL)return 0;
        if(head->next==NULL)return 1;
        return 1+length(head->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=length(head);
        int k=1;
        int index=l-n+1;
        if(index<=0)return head;
        ListNode*temp=head;
        if(index==1){
            head=temp->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        while(temp!=NULL){
            if(k==index-1){
                ListNode*target=temp->next;
                temp->next=temp->next->next;
                target->next=NULL;
                delete target;
                break;
            }
            temp=temp->next;
            k++;
        }
        return head;
        
    }
};