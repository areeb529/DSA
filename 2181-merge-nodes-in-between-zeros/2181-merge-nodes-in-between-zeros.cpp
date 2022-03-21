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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*temp=head;
        int sum=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*tail=dummy;
        while(temp){
            sum+=temp->val;
            if(temp->val==0&&sum){
                tail->next=temp;
                tail=temp;
                tail->val=sum;
                sum=0;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};