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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*prev=NULL,*cur=head,*nxt=head->next;
        while(cur){
            cur->next=prev;
            prev=cur;
            cur=nxt;
            if(nxt)
            nxt=nxt->next;
        }
        return prev;
    }
};