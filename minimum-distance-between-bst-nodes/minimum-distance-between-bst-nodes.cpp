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
    int minDiffInBST(TreeNode* root) {
        if(!root)return INT_MAX;
        int c=INT_MAX,d=INT_MAX;
        int a=minDiffInBST(root->left);
        int b=minDiffInBST(root->right);
        if(root->left){
            TreeNode*temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            c=abs(root->val-temp->val);
        }
        if(root->right){
            TreeNode*temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            d=abs(root->val-temp->val);
        }
        return min(min(a,b),min(c,d));
    }
};