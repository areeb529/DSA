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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> pN;
        pN.push(root);
        int left_most=root->val;
        pN.push(NULL);
        while(!pN.empty()){
            TreeNode*front=pN.front();
            pN.pop();
            if(front==NULL){
                if(pN.empty())break;
                else{
                    TreeNode*f=pN.front();
                    left_most=f->val;
                    pN.push(NULL);
                }
            }
            else{
                if(front->left!=NULL){
                    pN.push(front->left);
                }
                if(front->right!=NULL){
                    pN.push(front->right);
                }
            }
        }
        return left_most;
    }
};