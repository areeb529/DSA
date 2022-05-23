class Solution {
public:
    int maxProfit(vector<int>& prices,int i,int buy,int n,vector<vector<int>> &dp){
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+maxProfit(prices,i+1,0,n,dp),maxProfit(prices,i+1,1,n,dp));
        }
        else{
            profit=max(prices[i]+maxProfit(prices,i+2,1,n,dp),maxProfit(prices,i+1,0,n,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};