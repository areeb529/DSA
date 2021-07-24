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
    TreeNode*helper(TreeNode*root){
        if(!root)return root;
        TreeNode*l=helper(root->left);
        TreeNode*r=helper(root->right);
        root->left=NULL;
        TreeNode*temp=l;
        while(temp&&temp->right){
            temp=temp->right;
        }
        if(l){
            root->right=l;
            temp->right=r;
        }
        else{
            root->right=r;
        }
          return root;
    }
    void flatten(TreeNode* root) {
        root=helper(root);
    }
};