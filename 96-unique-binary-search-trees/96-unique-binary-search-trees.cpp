class Solution {
public:
    int helper(int n,vector<int> &dp){
        if(n==0)return 1;
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=0;i<=n-1;i++){
            ans+=(helper(i,dp)*helper(n-1-i,dp));
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};