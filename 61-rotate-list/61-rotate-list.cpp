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
    // ListNode*reverseLL(ListNode*head){
    //     if(head==NULL||head->next==NULL)return head;
    //     ListNode*newHead=reverseLL(head->next);
    //     head->next->next=head;
    //     head->next=NULL;
    //     return newHead;
    // }
    int lengthLL(ListNode*head){
        if(head==NULL)return 0;
        return 1+lengthLL(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)return head;
        int length=lengthLL(head);
        int y=k%length;
        if(y==0)return head;
        int ct=1;
        ListNode*temp=head;
        while(ct<length-y){
            temp=temp->next;
            ct++;
        }
        ListNode*newHead=temp->next;
        temp->next=NULL;
        temp=newHead;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return newHead;
    }
};