class Solution {
public:
    bool canJump(vector<int>& nums,int i,vector<int>&dp){
        int n=nums.size();
        if(i>=n-1)return 1;
        if(nums[i]==0)return 0;
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++){
            bool check=canJump(nums,i+j,dp);
            if(check)return dp[i]=1;
        }
        return dp[i]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return canJump(nums,0,dp);
    }
};