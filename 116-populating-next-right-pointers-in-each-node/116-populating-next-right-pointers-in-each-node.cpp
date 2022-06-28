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
        if(!root)return root;
        queue<Node*> pN;
        pN.push(root);
        while(!pN.empty()){
            int n=pN.size();
            for(int i=0;i<n;i++){
                Node*front=pN.front();
                pN.pop();
                if(i!=n-1){
                    front->next=pN.front();
                }
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