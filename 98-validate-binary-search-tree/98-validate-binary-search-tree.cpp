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
    vector<int> res;
    int i=0;
    bool helper(TreeNode*root){
        if(!root)return true;
        bool leftS=helper(root->left);
        if(!leftS)return false;
        res.push_back(root->val);
        int idx=i;
        i++;
        bool rightS=helper(root->right);
        if(!rightS)return false;
        if((root->left==NULL||res[idx-1]<res[idx])&&(root->right==NULL||res[idx]<res[idx+1]))return true;
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return helper(root);
    }
};