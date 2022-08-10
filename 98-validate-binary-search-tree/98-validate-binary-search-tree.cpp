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
    bool helper(TreeNode*minNode,TreeNode*root,TreeNode*maxNode){
       if(!root)return true;
       if(minNode&&minNode->val>=root->val||maxNode&&root->val>=maxNode->val)return false;
       return helper(minNode,root->left,root)&&helper(root,root->right,maxNode);
    }
    bool isValidBST(TreeNode* root) {
        return helper(NULL,root,NULL);
    }
};