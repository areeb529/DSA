class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int i,vector<int> &v, int target){
        if(target==0){
            ans.push_back(v);
            return;
            }
        if(i==candidates.size()){
            return;
        }
        helper(candidates,i+1,v,target);
        v.push_back(candidates[i]);
        if(candidates[i]<=target)
            helper(candidates,i,v,target-candidates[i]);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        helper(candidates,0,v,target);
        return ans;
    }
};