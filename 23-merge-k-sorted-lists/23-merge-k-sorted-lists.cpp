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
        bool operator()(const pair<ListNode*,int> &a,const pair<ListNode*,int> &b){
            return a.first->val>b.first->val||a.first->val==b.first->val&&a.second<b.second;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<ListNode*,int>,vector<pair<ListNode*,int>>,compare> pq;
        int k=lists.size();
        for(int i=0;i<k;i++){
            if(lists[i])
            pq.push({lists[i],i});
        }
        ListNode*head=NULL;
        ListNode*temp=NULL;
        while(!pq.empty()){
            pair<ListNode*,int> p=pq.top();
            pq.pop();
            
            if(head==NULL){
                head=p.first;
                temp=head;
            }
            else{
                temp->next=p.first;
                temp=p.first;
            }
            if(p.first->next){
                pq.push({p.first->next,p.second});
            }
        }
        return head;
    }
};