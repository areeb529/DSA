class Solution {
public:
   // int maxProfit(vector<int>& prices,int i,int buy,int n,vector<vector<int>> &dp){
   //      if(i==n)return 0;
   //      if(dp[buy][i]!=-1)return dp[buy][i];
   //      int profit=0;
   //      if(buy){
   //          int op1=-prices[i]+maxProfit(prices,i+1,0,n,dp);
   //          int op2=maxProfit(prices,i+1,1,n,dp);
   //          return dp[buy][i]=max(op1,op2);
   //      }
   //      else{
   //          int op1=prices[i]+maxProfit(prices,i+1,1,n,dp);
   //          int op2=maxProfit(prices,i+1,0,n,dp);
   //          return dp[buy][i]=max(op1,op2);
   //      }
   //  }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                int op1=-prices[i]+dp[(i+1)&1][0];
                int op2=dp[(i+1)&1][1];
                profit=max(op1,op2);
                }
                else{
                int op1=prices[i]+dp[(i+1)&1][1];
                int op2=dp[(i+1)&1][0];
                profit=max(op1,op2);
                }
                dp[i&1][buy]=profit;
            }
        }
        return dp[0][1];
    }
};