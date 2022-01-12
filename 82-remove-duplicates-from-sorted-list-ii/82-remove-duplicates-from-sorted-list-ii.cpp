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
        if(head->val==head->next->val){
            ListNode*cur=head;
            while(cur&&cur->next==NULL||cur&&cur->val==cur->next->val){
                cur=cur->next;
            }
            if(cur==NULL)return NULL;
            return deleteDuplicates(cur->next);
        }
        else{
            head->next=deleteDuplicates(head->next);
            return head;
        }
        
        
    }
};