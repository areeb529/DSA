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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*h=NULL,*t=NULL;
        int c=0;
        ListNode*t1=l1,*t2=l2;
        while(t1!=NULL||t2!=NULL||c==1){
            int v1=0,v2=0;
            if(t1)v1=t1->val;
            if(t2)v2=t2->val;
            
            int data=(v1+v2+c)%10;
            if(h==NULL){
                h=new ListNode(data);
                t=h;
            }
            else{
                t->next=new ListNode(data);
                t=t->next;
            }
            if(v1+v2+c>9)c=1;
            else c=0;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        return h;
    }
};