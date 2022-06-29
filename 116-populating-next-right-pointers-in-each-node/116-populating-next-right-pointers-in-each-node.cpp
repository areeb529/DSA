/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    // Node*connectNext(Node*root){
    //     if(!root||root->left==NULL||root->right==NULL)return root;
    //     root->left->next=root->right;
    //     if(root->next)
    //     root->right->next=root->next->left;
    //     Node*leftS=connectNext(root->left);
    //     Node*rightS=connectNext(root->right);
    //     return root;
    // }
    Node* connect(Node* root) {
        if(!root)return root;
        //return connectNext(root);
        Node*levelStart=root;
        while(levelStart){
            Node*cur=levelStart;
            while(cur){
                if(cur->left)cur->left->next=cur->right;
                if(cur->next&&cur->right)cur->right->next=cur->next->left;
                cur=cur->next;
            }
            levelStart=levelStart->left;
        }
        return root;
    }
};