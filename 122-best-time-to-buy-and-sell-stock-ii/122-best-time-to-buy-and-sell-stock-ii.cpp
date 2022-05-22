class Solution {
public:
    int maxProfit(vector<int>& prices,int i,int buy,int n,vector<vector<int>> &dp){
        if(i==n)return 0;
        if(dp[buy][i]!=-1)return dp[buy][i];
        int profit=0;
        if(buy){
            int op1=-prices[i]+maxProfit(prices,i+1,0,n,dp);
            int op2=maxProfit(prices,i+1,1,n,dp);
            return dp[buy][i]=max(op1,op2);
        }
        else{
            int op1=prices[i]+maxProfit(prices,i+1,1,n,dp);
            int op2=maxProfit(prices,i+1,0,n,dp);
            return dp[buy][i]=max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // int ans=0;
        // int boughtStockPrice=prices[0];
        // for(int i=0;i<n;i++){
        //     if(prices[i]>boughtStockPrice){
        //         ans=ans+prices[i]-boughtStockPrice;
        //     }
        //     boughtStockPrice=prices[i];
        // }
        // return ans;
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(n,-1));
        return maxProfit(prices,0,1,n,dp);
        
    }
};