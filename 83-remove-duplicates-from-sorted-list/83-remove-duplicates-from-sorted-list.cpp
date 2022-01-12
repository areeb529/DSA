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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*cur=head;
        ListNode*curNext=head->next;
        while(cur){
            if(curNext==NULL||cur->val!=curNext->val){
                cur->next=curNext;
                cur=curNext;
            }
            if(curNext)
            curNext=curNext->next;
        }
        return head;
    }
};