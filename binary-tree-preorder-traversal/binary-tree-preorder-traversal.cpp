/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;
        if(!root)return v;
        st.push(root);
        TreeNode*node=root;
        while(!st.empty()){
            if(node)
            v.push_back(node->val);
            if(node){
                node=node->left;
                if(node)
                st.push(node);
            }
            else{
                node=st.top();
                st.pop();
                node=node->right;
                if(node)st.push(node);
            }
        }
        return v;
    }
};