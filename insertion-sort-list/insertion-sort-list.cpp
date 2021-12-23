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
    ListNode* insertNode(ListNode*head,ListNode*node){
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp){
            if(temp->val>=node->val){
                node->next=temp;
                if(prev){
                    prev->next=node;
                }
                else {
                    head=node;
                }
                return head;
            }
            temp=temp->next;
            if(prev)
            prev=prev->next;
            else prev=head;
        }
        prev->next=node;
        return head;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*h1=head;
        ListNode*temp=head->next;
        h1->next=NULL;
        while(temp){
            ListNode*node=temp;
            temp=temp->next;
            node->next=NULL;
            h1=insertNode(h1,node);
        }
        return h1;
        
    }
};