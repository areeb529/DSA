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
    // int ans;
    // void helper(TreeNode* root, int &K){
    //     if(!root)return;
    //     helper(root->left,K);
    //     K--;
    //     if(K==0)ans=root->val;
    //     helper(root->right,K);
    // }
    int kthSmallest(TreeNode* root, int k) {
        // int K=k;
        // helper(root,K);
        // return ans;
        stack<TreeNode*> st;
        int ans;
        while(root||!st.empty()){
            TreeNode*cur=root;
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            root=st.top();
            st.pop();
            k--;
            if(k==0){
                ans=root->val;
                break;
            }
            root=root->right;
        }
        return ans;
    }
};