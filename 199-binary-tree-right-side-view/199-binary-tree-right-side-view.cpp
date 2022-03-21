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
        queue<TreeNode*> pN;
        pN.push(root);
        pN.push(NULL);
        vector<int> ans;
        if(!root)return ans;
        ans.push_back(root->val);
        while(!pN.empty()){
            TreeNode*front=pN.front();
            pN.pop();
            if(front==NULL){
                if(pN.empty())break;
                else{
                    ans.push_back(pN.front()->val);
                    pN.push(NULL);
                }
            }
            else{
                if(front->right){
                    pN.push(front->right);
                }
                if(front->left){
                    pN.push(front->left);
                }
            }
        }
        return ans;
    }
};