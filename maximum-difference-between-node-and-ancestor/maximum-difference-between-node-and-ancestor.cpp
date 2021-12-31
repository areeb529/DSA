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
    int ans=0;
    void maxAncestorDiff(TreeNode*root,int minV,int maxV){
        if(!root)return;
         minV=min(minV,root->val);
        maxV=max(maxV,root->val);
        ans=max(ans,maxV-minV);
        maxAncestorDiff(root->left,minV,maxV);
        maxAncestorDiff(root->right,minV,maxV);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxAncestorDiff(root,root->val,root->val);
        return ans;
    }
};