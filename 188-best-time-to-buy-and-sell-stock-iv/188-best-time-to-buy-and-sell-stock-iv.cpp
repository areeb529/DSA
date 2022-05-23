class Solution {
public:
    #define vi            vector<int>
    #define vii           vector<vector<int>> 
    int maxProfit(int k, vector<int>& prices) {
       int n=prices.size();
        if(n<=1||k<=0)return 0;
       vector<vector<int>> dp(2,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int j=1;j<=k;j++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[i]+dp[0][j],dp[1][j]);
                    }
                    else{
                        profit=max(prices[i]+dp[1][j-1],dp[0][j]);
                    }
                    dp[buy][j]=profit;
                }
            }
        }
        return dp[1][k];
    }
};