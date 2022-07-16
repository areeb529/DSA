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
   TreeNode* helper(vector<int>& preorder,int &i,int upper_bound=1001){
       if(i==preorder.size()||upper_bound<preorder[i]){
           i--;
           return NULL;
       }
       TreeNode*root=new TreeNode(preorder[i]);
       root->left=helper(preorder,++i,root->val);
       root->right=helper(preorder,++i,upper_bound);
       return root;
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        int i=0;
        return helper(preorder,i,1001);
       
    }
};