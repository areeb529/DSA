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
    vector<string> ans;
    void helper(TreeNode* root,string &s){
        if(!root)return;
        s.push_back('a'+root->val);
        if(root->left==NULL&&root->right==NULL){
            reverse(s.begin(),s.end());
            ans.push_back(s);
            reverse(s.begin(),s.end());
            s.pop_back();
            return;
        }
        helper(root->left,s);
        helper(root->right,s);
        s.pop_back();
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string s;
        helper(root,s);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};