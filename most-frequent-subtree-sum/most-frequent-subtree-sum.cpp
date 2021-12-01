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
    unordered_map<int,int> mp;
    int maxF=0;
    int sumTree(TreeNode* root){
        if(root==NULL)return 0;
        int l=sumTree(root->left);
        int r=sumTree(root->right);
        int sum=l+root->val+r;
        mp[sum]++;
        if(mp[sum]>maxF){
            maxF=mp[sum];
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int sum=sumTree(root);
        vector<int> ans;
        for(auto it:mp){
            if(it.second==maxF){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};