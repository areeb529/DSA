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
    vector<vector<int>> res;
    map<int,map<int,multiset<int>>> mp;
    void dfs(TreeNode* root,int row,int col){
        if(!root)return;
        mp[col][row].insert(root->val);
        dfs(root->left,row+1,col-1);
        dfs(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return res;
        dfs(root,0,0);
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