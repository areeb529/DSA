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
    int tilt=0;
    int sumTree(TreeNode*root){
        if(root==NULL)return 0;
        int leftSum=sumTree(root->left);
        int rightSum=sumTree(root->right);
        tilt+=abs(leftSum-rightSum);
        return leftSum+root->val+rightSum;
    }
    int findTilt(TreeNode* root) {
        int sum=sumTree(root);
        return tilt;
    }
};