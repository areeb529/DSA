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
    unordered_set<int> st;
    int res=0;
    void helper(TreeNode*root){
        if(!root)return;
        if(st.count(root->val)==1)st.erase(root->val);
        else st.insert(root->val);
        if(root->left==root->right){
            if(st.size()<=1)res++;
        }
        helper(root->left);
        helper(root->right);
        if(st.count(root->val)==1)st.erase(root->val);
        else st.insert(root->val);
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return res;
    }
};