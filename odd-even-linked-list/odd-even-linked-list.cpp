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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return NULL;
        ListNode*h1=NULL;
        ListNode*h2=NULL;
        ListNode*t1=NULL;
        ListNode*t2=NULL;
        ListNode*temp=head;
        int ct=0;
        while(temp){
            if(ct&1){
                if(h2==NULL){
                    h2=temp;
                    t2=temp;
                }
                else{
                    t2->next=temp;
                    t2=temp;
                }
            }
            else{
                if(h1==NULL){
                    h1=temp;
                    t1=temp;
                }
                else{
                    t1->next=temp;
                    t1=temp;
                }
            }
            temp=temp->next;
            ct++;
        }
        t1->next=h2;
        if(t2)
        t2->next=NULL;
        return h1;
    }
};