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
    TreeNode*prev=NULL;
    bool helper(TreeNode*root){
        if(!root)return true;
        bool leftS=helper(root->left);
        if(!leftS)return false;
        if(prev&&prev->val>=root->val)return false;
        prev=root;
        return helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};