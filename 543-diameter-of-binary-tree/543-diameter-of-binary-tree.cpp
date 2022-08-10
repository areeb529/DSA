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
    int diam=0;
    int height(TreeNode*root){
        if(!root)return 0;
        if(root->left==root->right)return 0;
        int lh=0,rh=0;
        lh=height(root->left);
        rh=height(root->right);
        int height=1+max(lh,rh);
        if(root->left)lh=1+lh;
        if(root->right)rh=1+rh;
        diam=max(diam,lh+rh);
        return height; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int treeHeight=height(root);
        return diam;
    }
};