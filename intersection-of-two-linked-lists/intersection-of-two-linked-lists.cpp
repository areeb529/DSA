/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *,bool> mp;
        ListNode*temp=headA;
        while(temp){
            mp[temp]=true;
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            if(mp.count(temp)==1)return temp;
            temp=temp->next;
        }
        return NULL;
        
    }
};