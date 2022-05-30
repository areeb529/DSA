/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* helper(Node* head){
        if(head==NULL)return NULL;
        Node*cur=new Node(head->val);
        cur->next=helper(head->next);
        mp[head]=cur;
        return cur;
    }
    Node* copyRandomList(Node* head) {
       Node*newHead=helper(head);
        Node*temp=newHead;
        Node*orig=head;
        mp[NULL]=NULL;
        while(temp){
            temp->random=mp[orig->random];
            temp=temp->next;
            orig=orig->next;
        }
        return newHead;
    }
};