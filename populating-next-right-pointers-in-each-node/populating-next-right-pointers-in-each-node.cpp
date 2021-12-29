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
    Node* connect(Node* root) {
        queue<Node*> pN;
        if(!root)return root;
        pN.push(root);
        pN.push(NULL);
        while(!pN.empty()){
            Node*front=pN.front();
            pN.pop();
            if(!front){
                if(pN.empty())break;
                else pN.push(NULL);
            }
            else{
                front->next=pN.front();
                if(front->left){
                    pN.push(front->left);
                }
                if(front->right){
                    pN.push(front->right);
                }
            }
        }
        return root;
    }
};