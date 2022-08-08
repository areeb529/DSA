class Solution {
public:
    bool helper(vector<int> &nums,int i,int n,vector<int> &dp){
        if(i==n)return true;
        if(i==n-1)return false;
        if(dp[i]!=-1)return dp[i];
        if(nums[i]==nums[i+1]){
            if(i+2<n&&nums[i+1]==nums[i+2]){
                return dp[i]=helper(nums,i+2,n,dp)||helper(nums,i+3,n,dp);
            }
            else{
                return dp[i]=helper(nums,i+2,n,dp);
            }
        }
        else{
            if(nums[i+1]-nums[i]==1){
                if(i+2<n&&nums[i+2]-nums[i+1]==1)return dp[i]=helper(nums,i+3,n,dp);
                else return dp[i]=false;
            }
            else return dp[i]=false;
        }
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper(nums,0,n,dp);
    }
};