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
    int diameter=0;
    int getHeight(TreeNode*root){
        if(!root)return 0;
        if(root->left==root->right)return 0;
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);
        int d1=0,d2=0;
        if(root->left){
            d1=1+leftHeight;
        }
        if(root->right){
            d2=1+rightHeight;
        }
        diameter=max(diameter,d1+d2);
        return 1+max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height=getHeight(root);
        return diameter;
    }
};