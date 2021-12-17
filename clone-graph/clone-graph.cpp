/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node*cloneGraph(Node* node,vector<Node*>&visited){
        if(node==NULL)return NULL;
        
        int value=node->val;
        if(visited[value])return visited[value];
        vector<Node*> &temp=node->neighbors;
        Node*root=new Node(value,temp);
        visited[value]=root;
        for(int i=0;i<temp.size();i++){
            root->neighbors[i]=cloneGraph(temp[i],visited);
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        vector<Node*> visited(101,NULL);
        return cloneGraph(node,visited);
    }
};