/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode*root,TreeNode*node,vector<TreeNode*> &v){
        if(!root)return false;
        v.push_back(root);
        if(root==node)return true;
        bool op1=getPath(root->left,node,v);
        bool op2=getPath(root->right,node,v);
        if(op1||op2)return true;
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathToP;
        bool f1=getPath(root,p,pathToP);
        vector<TreeNode*> pathToQ;
        bool f2=getPath(root,q,pathToQ);
        TreeNode*lca=NULL;
        for(int i=0;i<min(pathToP.size(),pathToQ.size())&&pathToP[i]==pathToQ[i];i++){
            lca=pathToP[i];
        }
        return lca;
    }
};