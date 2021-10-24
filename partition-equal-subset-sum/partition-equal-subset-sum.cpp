class Solution {
public:
    bool findSum(vector<int>& nums,int i,int sum,vector<vector<int>> &dp){
        if(i==nums.size()){
            if(sum==0)return true;
            return false;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool opt1=false;
        if(nums[i]<=sum)opt1=findSum(nums,i+1,sum-nums[i],dp);
        if(opt1)return dp[i][sum]=true;
        return dp[i][sum]=findSum(nums,i+1,sum,dp);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto &i:nums){
            sum+=i;
        }
        if(sum&1)return false;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return findSum(nums,0,sum/2,dp);
    }
};