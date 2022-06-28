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
    TreeNode*buildTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd){
        if(preStart>preEnd)return NULL;
        int leftPreS=preStart+1,leftInS=inStart,rightInE=inEnd,rightPreE=preEnd;
        int rootValue=preorder[preStart];
        int rootIndex=-1;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==rootValue){
                rootIndex=i;
                break;
            }
        }
        int leftInE=rootIndex-1;
        int rightInS=rootIndex+1;
        int leftPreE=leftPreS+leftInE-leftInS;
        int rightPreS=leftPreE+1;
        TreeNode*root=new TreeNode(rootValue);
        root->left=buildTree(preorder,leftPreS,leftPreE,inorder,leftInS,leftInE);
        root->right=buildTree(preorder,rightPreS,rightPreE,inorder,rightInS,rightInE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return buildTree(preorder,0,n-1,inorder,0,n-1);
    }
};