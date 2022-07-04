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
    vector<int> in;
    void helper(TreeNode* root){
        if(!root)return;
        helper(root->left);
        in.push_back(root->val);
        helper(root->right);
    }
    bool twoSum(int key){
        int i=0,j=in.size()-1;
        while(i<j){
            int sum=in[i]+in[j];
            if(sum==key)return true;
            else if(sum<key)i++;
            else j--;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        return twoSum(k);
    }
};