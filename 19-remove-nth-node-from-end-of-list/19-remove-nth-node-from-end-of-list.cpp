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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            length++;
        }
        int idx=1;
        temp=head;
        ListNode*H=new ListNode(-1);
        H->next=head;
        ListNode*prev=H;
        while(temp){
            if(idx==length-n+1){
                prev->next=temp->next;
                break;
            }
            prev=temp;
            temp=temp->next;
            idx++;
        }
        return H->next;
    }
};