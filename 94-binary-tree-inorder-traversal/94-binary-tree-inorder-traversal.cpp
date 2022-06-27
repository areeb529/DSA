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
        TreeNode*cur=root;
        TreeNode*temp=cur;
        vector<int> res;
        while(cur){
            temp=cur;
            if(cur->left){
                cur=cur->left;
                while(cur->right&&cur->right!=temp){
                    cur=cur->right;
                }
                if(cur->right==temp){
                    cur->right=NULL;
                    cur=temp;
                    res.push_back(cur->val);
                    cur=cur->right;
                }
                else{
                    cur->right=temp;
                    cur=temp->left;
                }
            }
            else{
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;
    }
};