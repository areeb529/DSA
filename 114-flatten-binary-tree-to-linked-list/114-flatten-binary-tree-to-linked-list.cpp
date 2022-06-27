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
    TreeNode*tail=NULL;
    TreeNode*flattenTree(TreeNode*root){
        // if(!root)return root;
        // if(root->right==NULL)tail=root;
        // TreeNode*leftS=flattenTree(root->left);
        // root->left=NULL;
        // TreeNode*rightChild=root->right;
        // root->right=leftS;
        // TreeNode*temp=tail;
        // TreeNode*rightS=flattenTree(rightChild);
        // if(temp){
        //     temp->right=rightS;
        // }
        // else{
        //     root->right=rightS;
        // }
        // return root;
        if(!root)return root;
        if(root->right==NULL){
            tail=root;
        }
        TreeNode*leftS=flattenTree(root->left);
        if(leftS==NULL)tail=root;
        root->left=NULL;
        TreeNode*temp=tail;
        TreeNode*rightS=flattenTree(root->right);
        if(temp){
            root->right=leftS;
            temp->right=rightS;
        }
        else{
            root->right=rightS;
        }
        return root;
        
    }
    void flatten(TreeNode* root) {
        root=flattenTree(root);
        
    }
};