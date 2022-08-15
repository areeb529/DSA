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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentMp;
        queue<TreeNode*> pN;
        pN.push(root);
        while(!pN.empty()){
            int n=pN.size();
            for(int i=0;i<n;i++){
                TreeNode*front=pN.front();
                pN.pop();
                if(front->left){
                    pN.push(front->left);
                    parentMp[front->left]=front;
                }
                if(front->right){
                    pN.push(front->right);
                    parentMp[front->right]=front;
                }
            }
        }
        unordered_set<TreeNode*> visited;
        pN.push(target);
        visited.insert(target);
        int level=0;
        vector<int> res;
        while(!pN.empty()){
            int n=pN.size();
            for(int i=0;i<n;i++){
                TreeNode*front=pN.front();
                pN.pop();
                if(level==k)res.push_back(front->val);
                if(parentMp.count(front)==1&&visited.count(parentMp[front])==0){
                    pN.push(parentMp[front]);
                    visited.insert(parentMp[front]);
                }
                if(front->left&&visited.count(front->left)==0){
                    pN.push(front->left);
                    visited.insert(front->left);
                }
                if(front->right&&visited.count(front->right)==0){
                    pN.push(front->right);
                    visited.insert(front->right);
                }
            }
            level++;
            if(level>k)break;
        }
        return res;
    }
};