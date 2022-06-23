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
   
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(!root)return res;
        st.push(root);
        TreeNode*node=root;
        while(!st.empty()){
           if(node){
               node=node->left;
               if(node)
               st.push(node);
           } 
           else{
                node=st.top();
                res.push_back(node->val);
                st.pop();
                node=node->right;
                if(node)
                st.push(node);
           }
        }
        return res;
    }
};