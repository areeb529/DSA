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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)return res;
        queue<TreeNode*> pN;
        pN.push(root);
        int leftToRight=1;
        while(!pN.empty()){
            int n=pN.size();
            vector<int> level(n);
            for(int i=0;i<n;i++){
                TreeNode*front=pN.front();
                pN.pop();
                if(leftToRight){
                    level[i]=front->val;
                }
                else{
                    level[n-i-1]=front->val;
                }
                if(front->left){
                    pN.push(front->left);
                }
                if(front->right){
                    pN.push(front->right);
                }
            }
            leftToRight^=1;
            res.push_back(level);
        }
        return res;
    }
};