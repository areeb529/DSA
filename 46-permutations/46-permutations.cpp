class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,int i,int n){
        if(i==n){
            res.push_back(nums);
            return;
        }
        for(int j=i+1;j<n;j++){
            swap(nums[i],nums[j]);
            helper(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
        helper(nums,i+1,n);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        helper(nums,0,n);
        return res;
    }
};