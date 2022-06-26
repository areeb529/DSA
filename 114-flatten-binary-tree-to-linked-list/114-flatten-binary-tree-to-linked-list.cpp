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
    TreeNode*flattenTree(TreeNode*root){
        if(!root)return root;
        TreeNode*flattenLeft=flattenTree(root->left);
        TreeNode*flattenRight=flattenTree(root->right);
        root->left=NULL;
        if(flattenLeft==NULL)root->right=flattenRight;
        else{
            TreeNode*cur=flattenLeft;
            while(cur->right){
                cur=cur->right;
            }
            root->right=flattenLeft;
            cur->right=flattenRight;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        root=flattenTree(root);
        
    }
};