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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)return res;
        queue<TreeNode*> pN;
        pN.push(root);
        while(!pN.empty()){
            int n=pN.size();
            for(int i=0;i<n;i++){
                TreeNode*front=pN.front();
                pN.pop();
                if(i==0)res.push_back(front->val);
                if(front->right){
                    pN.push(front->right);
                }
                if(front->left){
                    pN.push(front->left);
                }
            }
        }
        return res;
    }
};