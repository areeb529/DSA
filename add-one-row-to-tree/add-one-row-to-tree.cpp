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
    void helper(TreeNode* root, int val, int depth,int k){
        if(root==NULL)return;
        if(k==depth-1){
            TreeNode*node1=new TreeNode(val);
            TreeNode*node2=new TreeNode(val);
            node1->left=root->left;
            node2->right=root->right;
            root->left=node1;
            root->right=node2;
            return;
        }
        else{
            helper(root->left,val,depth,k+1);
            helper(root->right,val,depth,k+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*node=new TreeNode(val);
            node->left=root;
            return node;
        }
        helper(root,val,depth,1);
        return root;
    }
};