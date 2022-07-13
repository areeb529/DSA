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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> pQ;
        pQ.push(root);
        vector<vector<int>> v;
         while(!pQ.empty()){
             int len=pQ.size();
             vector<int> temp;
             for(int i=0;i<len;i++){
                 TreeNode*front=pQ.front();
                 temp.push_back(front->val);
                 pQ.pop();
                 if(front->left)pQ.push(front->left);
                 if(front->right)pQ.push(front->right);
             }
             v.push_back(temp);
             
         }
        return v;
    }
};