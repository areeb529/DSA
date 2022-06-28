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
    TreeNode* buildTree(vector<int>& inorder, int inS,int inE, vector<int>& postorder,int poS,int poE){
        if(inS>inE)return NULL;
        int rootValue=postorder[poE];
        int leftPoS=poS;
        int rightPoE=poE-1;
        int leftInS=inS;
        int rightInE=inE;
        int rootIndex=poE;
        for(int i=inS;i<=inE;i++){
            if(inorder[i]==rootValue){
                rootIndex=i;
                break;
            }
        }
        int leftInE=rootIndex-1,rightInS=rootIndex+1;
        int leftPoE=leftPoS+leftInE-leftInS;
        int rightPoS=leftPoE+1;
        TreeNode*root=new TreeNode(rootValue);
        root->left=buildTree(inorder,leftInS,leftInE,postorder,leftPoS,leftPoE);
        root->right=buildTree(inorder,rightInS,rightInE,postorder,rightPoS,rightPoE);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return buildTree(inorder,0,n-1,postorder,0,n-1);
    }
};