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
    class triplet{
    public:
      int x;
      int y;
      int z;
    };
    vector<vector<int>> ans;
    static bool compare(const triplet& a,const triplet &b){
        if(a.z<b.z){
            return true;
        }
        else if(a.z==b.z){
            if(a.y<b.y){
                return true;
            }
            else if(a.y==b.y){
                return a.x<=b.x;
            }
            return false;
        }
        else{
            return false;
        }
    }
    void dfs(TreeNode* root,int i,int j,vector<triplet> &mat){
        if(!root)return;
        mat.push_back({root->val,i,j});
        dfs(root->left,i+1,j-1,mat);
        dfs(root->right,i+1,j+1,mat);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<triplet> mat;
        dfs(root,0,0,mat);
        sort(mat.begin(),mat.end(),compare);
        vector<int> v;
        int k=mat.size();
        for(int i=0;i<k;i++){
            if(i==0){
                v.push_back(mat[i].x);
                if(k-1==0)ans.push_back(v);
            }
            else if(mat[i].z==mat[i-1].z){
                v.push_back(mat[i].x);
                if(i==k-1){
                    ans.push_back(v);
                }
            }
            else if(mat[i].z!=mat[i-1].z){
                ans.push_back(v);
                v={};
                v.push_back(mat[i].x);
                if(i==k-1){
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};