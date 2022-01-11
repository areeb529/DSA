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
    void sumRootLeaf(TreeNode* root,int sum){
        if(!root)return;
        sum=(sum<<1)|root->val;
        if(root->left==root->right){
            ans+=sum;
            return;
        }
        sumRootLeaf(root->left,sum);
        sumRootLeaf(root->right,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        sumRootLeaf(root,0);
        return ans;
    }
};