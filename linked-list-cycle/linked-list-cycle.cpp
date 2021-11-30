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
    bool hasCycle(ListNode *head) {
        ListNode*temp=head;
        unordered_set<ListNode*> mp;
        while(temp){
            if(mp.count(temp)==0){
                mp.insert(temp);
                temp=temp->next;
            }
            else{
                return true;
            }
        }
        return false;
    }
};