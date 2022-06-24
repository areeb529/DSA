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
    map<int,map<int,multiset<int>>> mp;
    void helper(TreeNode*root,int row,int col){
        if(!root)return;
        mp[col][row].insert(root->val);
        helper(root->left,row+1,col-1);
        helper(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);
        vector<vector<int>> res;
        for(auto &i:mp){
            vector<int> v;
            for(auto &j:i.second){
                for(auto &k:j.second){
                    v.push_back(k);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};