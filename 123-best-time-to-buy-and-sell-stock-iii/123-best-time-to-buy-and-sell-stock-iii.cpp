class Solution {
public:
    
    int maxProfit(vector<int>& prices,int i,int t,int n,vector<vector<int>> &dp){
        if(i==n||t==4)return 0;
        if(dp[i][t]!=-1)return dp[i][t];
        int profit=0;
        if(t%2==0){
            profit=max(-prices[i]+maxProfit(prices,i+1,t+1,n,dp),maxProfit(prices,i+1,t,n,dp));
        }
        else{
            profit=max(prices[i]+maxProfit(prices,i+1,t+1,n,dp),maxProfit(prices,i+1,t,n,dp));
        }
        return dp[i][t]=profit;
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return maxProfit(prices,0,0,n,dp);
    }
};