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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> pN;
        pN.push({root,0});
        int maxWidth=1;
        while(!pN.empty()){
            int n=pN.size();
            int width=0;
            long long minIdx=0,maxIdx=0;
            for(int i=0;i<n;i++){
                pair<TreeNode*,long long> front=pN.front();
                pN.pop();
                TreeNode* node=front.first;
                long long idx=front.second;
                if(i==0)minIdx=idx;
                if(i==n-1)maxIdx=idx;
                idx=idx-minIdx;
                if(node->left){
                    pN.push({node->left,2*idx+1});
                }
                if(node->right){
                    pN.push({node->right,2*idx+2});
                }
            }
            width=maxIdx-minIdx+1;
            maxWidth=max(maxWidth,width);
        }
        return maxWidth;
    }
};