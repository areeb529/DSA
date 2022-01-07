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
    int length=0;
    ListNode*H=NULL;
    Solution(ListNode* head) {
        H=head;
        length=0;
        ListNode*temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        
    }
    
    int getRandom() {
        int k=rand();
        int cnt=k%length;
        ListNode*temp=H;
        int ans=0;
        for(int i=0;i<=cnt&&temp;i++){
            if(i==cnt){
                ans=temp->val;
                break;
            }
            temp=temp->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */