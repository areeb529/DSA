class Solution {
public:
    int helper(vector<int>& prices,int i,int buy,int k,vector<vector<vector<int>>> &dp){
        if(i==prices.size()||k==0)return 0;
        if(dp[buy][i][k]!=-1)return dp[buy][i][k];
        if(buy){
            return dp[buy][i][k]=max(-prices[i]+helper(prices,i+1,0,k-1,dp),helper(prices,i+1,1,k,dp));
        }
        else{
            return dp[buy][i][k]=max(prices[i]+helper(prices,i+1,1,k-1,dp),helper(prices,i+1,0,k,dp));
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(2*k+1,-1)));
        return helper(prices,0,1,2*k,dp);
    }
};