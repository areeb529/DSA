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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k<=1)return head;
        ListNode*temp=head;
        int cnt=1;
        while(temp&&temp->next&&cnt<k){
         temp=temp->next;
         cnt++;
        }
        if(cnt<k)return head;
        ListNode*remListHead=NULL;
        if(temp){
            remListHead=temp->next;
            temp->next=NULL;
        }
        remListHead=reverseKGroup(remListHead,k);
        ListNode*prev=NULL,*cur=head,*nxt=head->next;
        while(cur){
            cur->next=prev;
            prev=cur;
            cur=nxt;
            if(nxt)
            nxt=nxt->next;
        }
        head->next=remListHead;
        head=prev;
        return head;
    }
};