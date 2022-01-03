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
    class compare{
        public:
        bool operator()(const ListNode* a,const ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        int k=lists.size();
        for(int i=0;i<k;i++){
            if(lists[i])
            pq.push(lists[i]);
        }
        ListNode*head=NULL;
        ListNode*temp=NULL;
        while(!pq.empty()){
            ListNode*minN=pq.top();
            pq.pop();
            
            if(head==NULL){
                head=minN;
                temp=head;
            }
            else{
                temp->next=minN;
                temp=minN;
            }
            if(minN->next){
                pq.push(minN->next);
            }
        }
        return head;
    }
};