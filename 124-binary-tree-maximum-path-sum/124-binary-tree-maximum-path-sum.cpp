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
    int maxSum=INT_MIN;
    int maxSumThroughNode(TreeNode*root){
        if(!root){
            return 0;
        }
        int leftS=maxSumThroughNode(root->left);
        int rightS=maxSumThroughNode(root->right);
        int ans=max(root->val,max(root->val+leftS,root->val+rightS));
        maxSum=max(maxSum,max(ans,root->val+leftS+rightS));
        //cout<<"val "<<root->val<<" ans "<<ans<<" maxSum "<<maxSum<<endl;
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        int maxSumAtRoot= maxSumThroughNode(root);
        return maxSum;
    }
};