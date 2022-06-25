/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(!root)return NULL;
        // else if(root==p||root==q)return root;
        // else {
        //     TreeNode*lcaOnLeft=lowestCommonAncestor(root->left,p,q);
        //     if(lcaOnLeft)return lcaOnLeft;
        //     TreeNode*lcaOnRight=lowestCommonAncestor(root->right,p,q);
        //     if(lcaOnRight)return lcaOnRight;
        //     return root;
        // }
        if(!root)return NULL;
        if(root==p||root==q)return root;
        TreeNode*lcaOnLeft=lowestCommonAncestor(root->left,p,q);
        TreeNode*lcaOnRight=lowestCommonAncestor(root->right,p,q);
        if(lcaOnLeft&&lcaOnRight)return root;
        else if(lcaOnLeft)return lcaOnLeft;
        else if(lcaOnRight)return lcaOnRight;
        else return NULL;
        
        
    }
};