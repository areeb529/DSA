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
        //APPROACH 1
//         if(head==NULL||head->next==NULL)return head;
//         ListNode*prev=NULL;
//         ListNode*cur=head;
//         while(cur){
//             while(cur&&cur->next&&cur->val==cur->next->val){
//                 cur=cur->next;
//                 if(cur->next==NULL||cur->val!=cur->next->val){
//                     cur=cur->next;
//                 }
//             }
//             if(prev)
//             prev->next=cur;
//             else head=cur;
//             prev=cur;
//             if(cur)
//             cur=cur->next;
            
//         }
//         return head;
        
        
        if(head==NULL||head->next==NULL)return head;
        ListNode*dummy=new ListNode(-101);
        ListNode*prev=dummy;
        ListNode*cur=head;
        ListNode*curNext=head->next;
        bool f=false;
        while(cur){
            if(curNext==NULL||cur->val!=curNext->val){
                if(!f){
                    prev->next=cur;
                    prev=cur;
                }
                else if(curNext==NULL&&f)prev->next=NULL;
                f=false;
            }
            else{
                f=true;
            }
            cur=curNext;
            if(curNext)
            curNext=curNext->next;
        }
        return dummy->next;
    }
};