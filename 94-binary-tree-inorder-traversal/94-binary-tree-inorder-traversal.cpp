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
   
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,bool>> st;
        vector<int> res;
        if(!root)return res;
        st.push({root,false});
        while(!st.empty()){
            TreeNode*node=st.top().first;
            bool pushedLeft=st.top().second;
            if(!pushedLeft&&node->left){
                st.top().second=true;
                st.push({node->left,false});
            }
            else{
                res.push_back(node->val);
                st.pop();
                if(node->right)
                st.push({node->right,false});
            }
        }
        return res;
    }
};