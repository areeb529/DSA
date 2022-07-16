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
    unordered_map<int,int> mp;
    TreeNode*buildTree(vector<int>& preorder,vector<int>& inorder,int preS,int preE,int inS,int inE){
        if(inS>inE)return NULL;
        int leftPreS=preS+1;
        int rightPreE=preE;
        int leftInS=inS;
        int rightInE=inE;
        int rootValue=preorder[preS];
        TreeNode*root=new TreeNode(rootValue);
        int rootIndex=mp[rootValue];
        
        int leftInE=rootIndex-1;
        int rightInS=rootIndex+1;
        int leftPreE=leftPreS+leftInE-leftInS;
        int rightPreS=leftPreE+1;
        root->left=buildTree(preorder,inorder,leftPreS,leftPreE,leftInS,leftInE);
        root->right=buildTree(preorder,inorder,rightPreS,rightPreE,rightInS,rightInE);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return buildTree(preorder,inorder,0,n-1,0,n-1);
    }
};