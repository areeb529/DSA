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
        if(!root)return NULL;
        if(root==p||root==q)return root;
        TreeNode*leftS=lowestCommonAncestor(root->left,p,q);
        TreeNode*rightS=lowestCommonAncestor(root->right,p,q);
       
        if(leftS&&rightS)return root;
        else if(leftS)return leftS;
        else if(rightS)return rightS;
        else return NULL;
        
    }
};