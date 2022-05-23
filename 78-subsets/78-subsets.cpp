class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,int i,int n,vector<int> &v){
        if(i==n){
            res.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        helper(nums,i+1,n,v);
        v.pop_back();
        helper(nums,i+1,n,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        helper(nums,0,n,v);
        return res;
    }
};