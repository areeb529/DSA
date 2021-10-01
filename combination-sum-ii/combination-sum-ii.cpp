class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates,int i,vector<int> &v, int target,int n){
        if(i==n){
            if(target==0){
            ans.push_back(v);
        }
            return;
        }
        if(candidates[i]<=target){
            v.push_back(candidates[i]);
            helper(candidates,i+1,v,target-candidates[i],n);
            v.pop_back();
        }
        int j=i+1;
        for(j=i+1;j<n;j++){
            if(candidates[j]!=candidates[j-1])break;
        }
        helper(candidates,j,v,target,n);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,v,target,n);
        return ans;
    }
};