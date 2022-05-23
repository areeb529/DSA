class Solution {
public:
    #define vi            vector<int>
    #define vii           vector<vector<int>> 
    
    int maxProfit(vector<int>& prices,int i,int buy,int k,int n,vector<vii> &dp){
        if(i==n||k<=0) return 0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+maxProfit(prices,i+1,0,k,n,dp),maxProfit(prices,i+1,1,k,n,dp));
        }
        else{
            profit=max(prices[i]+maxProfit(prices,i+1,1,k-1,n,dp),maxProfit(prices,i+1,0,k,n,dp));
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        int k=2;
        vector<vii> dp(n+1,vii(2,vi(3)));
        //vector<vector<int>> dp(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int k=1;k<=2;k++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else{
                        profit=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                    dp[i][buy][k]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};