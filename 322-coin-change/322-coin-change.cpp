class Solution {
public:
    int helper(vector<int> &coins,int i,int amount,vector<vector<int>> &dp){
       if(i==coins.size()||amount<=0){
           return (amount==0)?0:INT_MAX-1;
       }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int ans=-1;
        if(amount<coins[i]){
            int coinNotTaken=helper(coins,i+1,amount,dp);
            ans=coinNotTaken;
        }
        else{
            int coinTaken=1+helper(coins,i,amount-coins[i],dp);
            int coinNotTaken=helper(coins,i+1,amount,dp);
            ans=min(coinTaken,coinNotTaken);
        }
        return dp[i][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=helper(coins,0,amount,dp);
        return ans==INT_MAX-1?-1:ans;
    }
};