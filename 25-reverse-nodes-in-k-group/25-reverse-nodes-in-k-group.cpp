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
        if(head==NULL||head->next==NULL||k==1)return head;
        ListNode*temp=head;
        int cnt=k;
        cnt--;
        while(cnt--&&temp){
            temp=temp->next;
        }
        if(!temp)return head;
        ListNode*nextHead=temp->next;
        temp->next=NULL;
        ListNode*prev=NULL;
        ListNode*cur=head;
        ListNode*nxt=cur->next;
        while(cur){
            cur->next=prev;
            prev=cur;
            cur=nxt;
            if(nxt)nxt=nxt->next;
        }
        head->next=reverseKGroup(nextHead,k);
        return prev;
    }
};