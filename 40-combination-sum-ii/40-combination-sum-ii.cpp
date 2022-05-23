class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candidates,int i,int n,int target,vector<int> sub){
        if(i==n){
            if(target==0)res.push_back(sub);
            return;
        }
        if(target-candidates[i]>=0){
            sub.push_back(candidates[i]);
            helper(candidates,i+1,n,target-candidates[i],sub);
            sub.pop_back();
        }
        int j=i;
        while(j+1<n&&candidates[j]==candidates[j+1])j++;
        helper(candidates,j+1,n,target,sub);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> sub;
        helper(candidates,0,n,target,sub);
        return res;
    }
};