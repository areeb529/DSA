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
//     int totalNodes;
//     void helper(TreeNode*root,int height){
//         if(root==NULL){
//             totalNodes-=height;
//             return;
//         }
//         TreeNode*node=root->left;
   
//         int subTreeHeight=height-1;
//         while(node){
//             node=node->right;
//             subTreeHeight--;
//         }
//         if(subTreeHeight==0){
//             helper(root->right,height-1);
//         }
//         else{
//             totalNodes-=(1<<(height-2));
//             helper(root->left,height-1);
//         }
//     }
    int countNodes(TreeNode* root) {
        // int height=0;
        // if(root==NULL)return 0;
        // TreeNode*temp=root;
        // while(temp){
        //     height++;
        //     temp=temp->left;
        // }
        // totalNodes=(1<<(height))-1;
        // helper(root,height);
        // return totalNodes;
        if(root==NULL)return 0;
        TreeNode*node=root->left;
        int lh=0,rh=0;
        while(node){
            node=node->left;
            lh++;
        }
        node=root->right;
        while(node){
            node=node->right;
            rh++;
        }
        if(lh==rh){
            return ((1<<(lh+1))-1);
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
        
    }
};