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
    // Node* helper(Node* head){
    //     if(head==NULL)return NULL;
    //     Node*cur=new Node(head->val);
    //     cur->next=helper(head->next);
    //     cur->random=head;
    //     return cur;
    // }
    Node*helper(Node* head){
        if(head==NULL)return NULL;
        Node*temp=head->next;
        head->next=new Node(head->val);
        Node*h1=head->next;
        h1->next=helper(temp);;
        if(head->random)
        h1->random=head->random->next;
        return head;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
       head=helper(head);
        Node*temp=head;
        Node*newHead=head->next;
        while(temp){
            Node*nxt=temp->next;
            temp->next=temp->next->next;
            if(nxt&&nxt->next)
            nxt->next=nxt->next->next;
            temp=temp->next;
        }
        return newHead;
       
    }
};