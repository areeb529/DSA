/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp=headA;
        while(temp){
            temp->val=-temp->val;
            temp=temp->next;
        }
        ListNode*ans=NULL;
        temp=headB;
        while(temp){
            if(temp->val<0){
                ans=temp;
                break;
            }
            temp=temp->next;
        }
        temp=headA;
        while(temp){
            temp->val=abs(temp->val);
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            temp->val=abs(temp->val);
            temp=temp->next;
        }
        return ans;
        
        
    }
};