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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> pN;
        pN.push(root);
        int levelIndex=0;
        while(!pN.empty()){
            int n=pN.size();
            int prev;
            if(levelIndex&1){
                prev=INT_MAX;
            }
            else{
                prev=INT_MIN;
            }
            for(int i=0;i<n;i++){
                TreeNode*front=pN.front();
                pN.pop();
                if(levelIndex&1){
                    if(front->val%2!=0||prev<=front->val)return false;
                    else prev=front->val;
                }
                else{
                    if(front->val%2==0||prev>=front->val)return false;
                    else prev=front->val;
                }
                if(front&&front->left){
                    pN.push(front->left);
                }
                if(front&&front->right){
                    pN.push(front->right);
                }
            }
            levelIndex=levelIndex^1;
        }
        return true;
    }
};