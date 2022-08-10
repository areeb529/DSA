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
    bool helper(TreeNode*node1,TreeNode*node2){
        if(node1==NULL&&node2==NULL)return true;
        else if(node1==NULL||node2==NULL)return false;
        else{
            return node1->val==node2->val&&helper(node1->left,node2->right)&&helper(node1->right,node2->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
};