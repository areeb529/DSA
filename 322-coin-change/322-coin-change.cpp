class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int j=1;j<=amount;j++){
            dp[n][j]=INT_MAX-1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=amount;j++){
                if(j<coins[i]){
                    dp[i][j]=dp[i+1][j];
                }
                else{
                    dp[i][j]=min(1+dp[i][j-coins[i]],dp[i+1][j]);
                }
            }
        }
        int ans= dp[0][amount];
        return ans==INT_MAX-1?-1:ans;
    }
};