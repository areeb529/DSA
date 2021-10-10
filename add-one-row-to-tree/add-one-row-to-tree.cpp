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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*node=new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*> pN;
        int k=1;
        pN.push(root);
        pN.push(NULL);
        while(!pN.empty()){
            TreeNode*front=pN.front();
            pN.pop();
            if(front==NULL){
                k++;
                if(pN.empty()||k>=depth)break;
                else pN.push(NULL);
            }
            else{
                    if(k==(depth-1)){
                        TreeNode*node1=new TreeNode(val);
                        node1->left=front->left;
                        front->left=node1;
                    }
                    if(front->left!=NULL)
                    pN.push(front->left);
                    if(k==(depth-1)){
                        TreeNode*node2=new TreeNode(val);
                        node2->right=front->right;
                        front->right=node2;
                    }
                    if(front->right!=NULL)
                    pN.push(front->right);
            }
        }
        return root;
    }
};