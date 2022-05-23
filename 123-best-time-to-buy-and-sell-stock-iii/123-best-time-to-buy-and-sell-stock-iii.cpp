class Solution {
public:
    #define vi            vector<int>
    #define vii           vector<vector<int>> 
    
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        int k=2;
        //vector<vii> dp(n+1,vii(2,vi(3)));
        vector<vector<int>> dp(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int k=1;k<=2;k++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[i]+dp[0][k],dp[1][k]);
                    }
                    else{
                        profit=max(prices[i]+dp[1][k-1],dp[0][k]);
                    }
                    dp[buy][k]=profit;
                }
            }
        }
        return dp[1][2];
    }
};