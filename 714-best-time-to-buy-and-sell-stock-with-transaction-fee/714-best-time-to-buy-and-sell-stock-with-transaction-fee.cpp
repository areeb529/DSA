class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> dp(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[i]+dp[0],dp[1]);
                }
                else{
                    profit=max(prices[i]+dp[1]-fee,dp[0]);
                }
                dp[buy]=profit;
            }
        }
        return dp[1];
    }
};