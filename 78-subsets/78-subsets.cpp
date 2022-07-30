class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums,int i,vector<int> &v){
        if(i==nums.size()){
            res.push_back(v);
            return;
        }
        helper(nums,i+1,v);
        v.push_back(nums[i]);
        helper(nums,i+1,v);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        helper(nums,0,v);
        return res;
    }
};