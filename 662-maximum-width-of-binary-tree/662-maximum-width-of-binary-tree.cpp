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
        // queue<pair<TreeNode*,long long>> pN;
        // pN.push({root,0});
        // long long maxWidth=0;
        // while(!pN.empty()){
        //     int n=pN.size();
        //     long long minIdx=0,maxIdx=0;
        //     long long start=0;
        //     long long prev=-1;
        //     for(int i=0;i<n;i++){
        //         TreeNode*front=pN.front().first;
        //         long long idx=pN.front().second;
        //         cout<<"idx "<<idx<<" ";
        //         pN.pop();
        //         if(front->left){
        //             if(prev==-1){
        //                 start=0;
        //                 prev=2*idx+1;
        //             }
        //             else{
        //                 start=start+2*idx+1-prev;
        //                 prev=2*idx+1;
        //             }
        //             cout<<"s p "<<start<<" "<<prev<<" ";
        //             pN.push({front->left,start});
        //         }
        //         if(front->right){
        //             if(prev==-1){
        //                 start=0;
        //                 prev=2*idx+2;
        //             }
        //             else{
        //                 start=start+2*idx+2-prev;
        //                 prev=2*idx+2;
        //             }
        //             cout<<"s p "<<start<<" "<<prev<<" ";
        //             pN.push({front->left,start});
        //         }
        //         if(i==0){
        //             minIdx=idx;
        //         }
        //         if(i==n-1){
        //             maxIdx=idx;
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        //     maxWidth=max(maxWidth,maxIdx-minIdx+1);
        //     cout<<"width"<<" "<<maxIdx-minIdx+1<<endl;
        // }
        // return maxWidth;
        queue<pair<TreeNode*,long long>> pN;
        pN.push({root,0});
        long long maxWidth=0;
        while(!pN.empty()){
            int n=pN.size();
            long long minIdx=0,maxIdx=0;
            for(int i=0;i<n;i++){
                TreeNode*front=pN.front().first;
                long long idx=pN.front().second;
                pN.pop();
                if(i==0){
                    minIdx=idx;
                }
                if(i==n-1){
                    maxIdx=idx;
                }
                idx=idx-minIdx;
                if(front->left){
                    pN.push({front->left,2*idx+1});
                }
                if(front->right){
                    pN.push({front->right,2*idx+2});
                }
                
            }
            maxWidth=max(maxWidth,maxIdx-minIdx+1);
        }
        return maxWidth;
    }
};