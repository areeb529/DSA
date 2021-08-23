class Solution {
public:
    int helper(vector<int>&cost,int n,int i,vector<int>&dp){
        if(n==0||n==1){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int opt1=cost[i]+helper(cost,n-1,i+1,dp);
        int opt2=cost[i+1]+helper(cost,n-2,i+2,dp);
        return dp[i]=min(opt1,opt2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int ans=helper(cost,n,0,dp);
        return ans;
    }
};