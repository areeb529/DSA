class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(2));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[i]+dp[(i+1)&1][0],dp[(i+1)&1][1]);
                }
                else{
                    profit=max(prices[i]+dp[(i+2)&1][1],dp[(i+1)&1][0]);
                }
                dp[i&1][buy]=profit;
            }
        }
        return dp[0][1];
    }
};