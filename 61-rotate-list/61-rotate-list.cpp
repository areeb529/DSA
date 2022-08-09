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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)return head;
        int length=0;
        ListNode*tail=head;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            if(temp&&temp->next==NULL)tail=temp;
            length++;
        }
        k=k%length;
        if(k==0)return head;
        int cnt=length-k;
        cnt--;
        temp=head;
        while(cnt--){
            temp=temp->next;
        }
        ListNode*newHead=temp->next;
        temp->next=NULL;
        tail->next=head;
        return newHead;
    }
};