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
    vector<int> postorderTraversal(TreeNode* root) {
        // stack<TreeNode*> st;
        // while(){
        //     while(root){
        //         st.push(root);
        //         root=root->left;
        //     }
        //     root=st.top();
        //     root=root->right;
        //     if(!root)res.push_back()
        // }
        
        stack<TreeNode*> st;
        vector<int> res;
        while(root||!st.empty()){
            TreeNode*prev=root;
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            root=root->right;
            if(root)continue;
            prev=root;
            root=st.top();
            while(!st.empty()&&root->right==NULL||root->right==prev){
                st.pop();
                res.push_back(root->val);
                prev=root;
                if(!st.empty())
                root=st.top();
                else{
                    root=NULL;
                    break;
                }
            }
            if(root)
            root=root->right;
        }
        return res;
        
    }
};