class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size(),w=amount;
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        for(int i=n;i>=0;i--){
            for(int j=0;j<=w;j++){
                if(j==0)dp[i][j]=1;
                else if(i==n)dp[i][j]=0;
                else if(coins[i]>j)dp[i][j]=dp[i+1][j];
                else dp[i][j]=dp[i+1][j]+dp[i][j-coins[i]];
            }
        }
        return dp[0][w];
    }
};