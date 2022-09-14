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
    int res=0;
    void helper(TreeNode*root,vector<int> &freq){
        if(!root)return;
        freq[root->val-1]++;
        if(root->left==root->right){
            int oddFreqCnt=0;
            for(int i=0;i<9;i++){
                if(freq[i]&1)oddFreqCnt++;
            }
            if(oddFreqCnt<=1)res++;
            freq[root->val-1]--;
            return;
        }
        helper(root->left,freq);
        helper(root->right,freq);
        freq[root->val-1]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(9,0);
        helper(root,freq);
        return res;
    }
};