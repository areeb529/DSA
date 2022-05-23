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
        vector<vii> dp(n,vii(2,vi(3,-1)));
        return maxProfit(prices,0,1,k,n,dp);
        
    }
};