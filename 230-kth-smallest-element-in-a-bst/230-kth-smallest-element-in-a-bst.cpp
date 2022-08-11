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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode*cur=root;
        int ct=0;
        int ans=-1;
        while(true){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            if(st.empty())break;
            ct++;
            if(ct==k){
                ans=st.top()->val;
                break;
            }
            cur=st.top()->right;
            st.pop();
        }
        return ans;
    }
};