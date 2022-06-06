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
        ListNode*p1=headA;
        ListNode*p2=headB;
        int length1=0,length2=0;
        while(p1){
            p1=p1->next;
            length1++;
        }
        while(p2){
            p2=p2->next;
            length2++;
        }
        int diff=abs(length2-length1);
        ListNode*ans=NULL;
        if(length2<=length1){
            p1=headA;
            p2=headB;
        }
        else{
            p1=headB;
            p2=headA;
        }
        while(diff--){
            p1=p1->next;
        }
        while(p1&&p2){
            if(p1==p2){
                ans=p1;
                break;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return ans;
        
        
        
        
    }
};