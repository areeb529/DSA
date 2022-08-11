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
    TreeNode*prev=NULL;
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode*cur=root;
        TreeNode*prev=NULL;
        while(true){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            if(st.empty())break;
            if(prev&&prev->val>=st.top()->val)return false;
            prev=st.top();
            cur=st.top()->right;
            st.pop();
        }
        return true;
    }
};