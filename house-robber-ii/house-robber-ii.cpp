class Solution {
public:
    int helper(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int opt1=nums[i]+helper(nums,i+2,dp);
        int opt2=helper(nums,i+1,dp);
        return dp[i]=max(opt1,opt2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int i=0;
        vector<int> dp2(n,-1);
        int opt2=helper(nums,i+1,dp2);
        nums.pop_back();
        vector<int> dp1(n+1,-1);
        int opt1=nums[i]+helper(nums,i+2,dp1);
        return max(opt1,opt2);
    }
};