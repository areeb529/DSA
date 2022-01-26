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
    void mergeTwoSortedArrays(vector<int> &v1,vector<int> &v2,vector<int> &ans){
        int m=v1.size(),n=v2.size(),i=0,j=0,k=0;
        while(i<m&&j<n){
            if(v1[i]<v2[j]){
                ans[k++]=v1[i++];
            }
            else{
                ans[k++]=v2[j++];
            }
        }
        while(i<m){
            ans[k++]=v1[i++];
        }
        while(j<n){
            ans[k++]=v2[j++];
        }
    }
    void inorder(TreeNode*root,vector<int> &ans){
        if(!root)return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        inorder(root1,v1);
        vector<int> v2;
        inorder(root2,v2);
        int m=v1.size(),n=v2.size();
        if(m==0){
            return v2;
        }
        else if(n==0){
            return v1;
        }
        else{
            vector<int> ans(m+n);
            mergeTwoSortedArrays(v1,v2,ans);
            return ans;
        }
    }
};