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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode*cur=root;
        TreeNode*temp=root;
        while(cur){
            temp=cur;
            res.push_back(cur->val);
            if(cur->left){
                cur=cur->left;
                while(cur->right&&cur->right!=temp){
                    cur=cur->right;
                }
                if(cur->right==temp){
                    cur->right=NULL;
                    res.pop_back();
                    cur=temp->right;
                }
                else{
                    cur->right=temp;
                    cur=temp->left;
                }
            }
            else{
                cur=cur->right;
            }
        }
        return res;
    }
};