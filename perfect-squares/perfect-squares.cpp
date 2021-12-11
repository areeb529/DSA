class Solution {
public:
    int numSquares(int n,vector<int> &dp){
        if(n==0||n==1){
            return n;
        }
        if(dp[n]!=-1)return dp[n];
        int ans=INT_MAX;
        for(int i=1;n-i*i>=0;i++){
            ans=min(ans,1+numSquares(n-i*i,dp));
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return numSquares(n,dp);
    }
};