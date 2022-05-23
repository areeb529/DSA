class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &candidates,int i,int n,vector<int> &sub,int target){
        if(i==n){
            if(target==0)res.push_back(sub);
            return;
        }
        if(target-candidates[i]>=0){
            sub.push_back(candidates[i]);
            helper(candidates,i,n,sub,target-candidates[i]);
            sub.pop_back();   
        }
        helper(candidates,i+1,n,sub,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> sub;
        helper(candidates,0,n,sub,target);
        return res;
    }
};