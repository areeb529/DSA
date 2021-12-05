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
    unordered_map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        if(root==NULL)return 0;
        if(mp.count(root)==1)return mp[root];
        int op1=0;
        if(root->left)op1=rob(root->left->left)+rob(root->left->right);
        int op2=0;
        if(root->right)op2=rob(root->right->left)+rob(root->right->right);
        int op3=rob(root->left)+rob(root->right);
        return mp[root]=max(root->val+op1+op2,op3);
    }
};