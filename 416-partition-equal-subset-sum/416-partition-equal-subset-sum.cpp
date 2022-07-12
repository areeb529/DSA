class Solution {
public:
    bool helper(vector<int>& nums,int i,int sum,int n,vector<vector<int>> &dp){
        if(i==n){
            if(sum==0)return true;
            else return false;
        }
        if(sum==0)return true;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool op1=false,op2=false;
        if(sum>=nums[i])
        op1=helper(nums,i+1,sum-nums[i],n,dp);
        op2=helper(nums,i+1,sum,n,dp);
        bool res=op1||op2;
        return dp[i][sum]=res;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1)return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return helper(nums,0,sum/2,n,dp);
    }
};