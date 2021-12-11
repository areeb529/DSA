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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        queue<TreeNode*> pN;
        pN.push(root);
        pN.push(NULL);
        int maxNum=INT_MIN;
        while(!pN.empty()){
            TreeNode*front=pN.front();
            pN.pop();
            if(front==NULL){
                ans.push_back(maxNum);
                maxNum=INT_MIN;
                if(pN.empty())break;
                else pN.push(NULL);
            }
            else{
             maxNum=max(maxNum,front->val);
                if(front->left)pN.push(front->left);
                if(front->right)pN.push(front->right);
            }
            
        }
        return ans;
    }
};