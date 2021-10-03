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
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> pN;
        vector<int> v;
        pN.push(NULL);
        pN.push(root);
        v.push_back(root->val);
        
        int c=1;
        while(!pN.empty()){
            TreeNode*front=pN.front();
            pN.pop();
            if(front==NULL){
                if(c==1){
                    c=0;
                }
                else{
                    reverse(v.begin(),v.end());
                    c=1;
                }
                if(pN.empty())break;
                else pN.push(NULL);
                ans.push_back(v);
                v.clear();
                
            }
            else{
                if(front->left){
                    pN.push(front->left);
                    v.push_back(front->left->val);
                }
                if(front->right){
                    pN.push(front->right);
                    v.push_back(front->right->val);
                }
            }
        }
        return ans;
    }
};