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
    // bool isValidBST(TreeNode*root,TreeNode*maxNode,TreeNode*minNode){
    //     if(!root)return root;
    //     maxNode=
    // }
    bool helper(TreeNode*root,long minNode=-100000000000,long maxNode=100000000000){
        if(!root)return true;
        if(minNode<root->val&&root->val<maxNode&&helper(root->left,minNode,root->val)&&helper(root->right,root->val,maxNode))return true;
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return helper(root);
    }
};