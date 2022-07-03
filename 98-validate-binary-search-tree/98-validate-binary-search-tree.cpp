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
    // bool isValidBST(TreeNode*root,TreeNode*maxNode,TreeNode*minNode){
    //     if(!root)return root;
    //     maxNode=
    // }
    vector<int> res;
    bool isValidBST(TreeNode* root) {
       stack<TreeNode*> st;
        long prev=-1e11;
        while(root||!st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            if(prev>=root->val)return false;
            prev=root->val;
            st.pop();
            root=root->right;
        }
        return true;
        
    }
};