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
    bool checkSymmetry(TreeNode*node1,TreeNode*node2){
        if(node1&&node2){
            return node1->val==node2->val&&checkSymmetry(node1->left,node2->right)&&checkSymmetry(node1->right,node2->left);
        }
        else{
            if(node1==NULL&&node2==NULL)return true;
            else return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left,root->right);
    }
};