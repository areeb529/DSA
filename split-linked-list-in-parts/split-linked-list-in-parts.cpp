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
    int length(ListNode*head){
        if(head==NULL)return 0;
        return 1+length(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l=length(head);
        int partSize=l/k;
        int rem=l%k;
        vector<int> partSizes(k,partSize);
        int i=0;
        while(rem){
            partSizes[i]++;
            rem--;
            i=(i+1)%k;
        }
        vector<ListNode*> ans;
        ListNode*temp=head;
        for(int i=0;i<k;i++){
            ans.push_back(temp);
            for(int j=1;j<partSizes[i];j++){
                temp=temp->next;
            }
            if(temp){
            ListNode*n=temp->next;
            temp->next=NULL;
            temp=n;
            }
        }
        return ans;
        
    }
};