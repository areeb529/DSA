class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,int i,vector<int>& v){
        if(i==nums.size()){
            res.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        helper(nums,i+1,v);
        v.pop_back();
        int j=i+1;
        while(j<nums.size()&&nums[j]==nums[j-1])j++;
        helper(nums,j,v);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> v;
        helper(nums,0,v);
        return res;
    }
};