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
    int nodeMaxPathSum(TreeNode* root){
        if(!root)return 0;
        int leftSum=nodeMaxPathSum(root->left);
        int rightSum=nodeMaxPathSum(root->right);
        if(leftSum<0&&rightSum<0)return root->val;
        return root->val+max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int leftMax=maxPathSum(root->left);
        int rightMax=maxPathSum(root->right);
        int rootMaxPath=root->val;
        int leftRootMaxSum=nodeMaxPathSum(root->left);
        int rightRootMaxSum=nodeMaxPathSum(root->right);
        if(leftRootMaxSum>0)rootMaxPath+=leftRootMaxSum;
        if(rightRootMaxSum>0)rootMaxPath+=rightRootMaxSum;
        if(root->left==NULL){
            leftMax=INT_MIN;
        }
        if(root->right==NULL){
            rightMax=INT_MIN;
        }
        return max(rootMaxPath,max(leftMax,rightMax));
    }
};