class Solution {
public:
    int helper(vector<int> &coins,int i,int amount,vector<vector<int>> &dp){
        if(i==coins.size()||amount==0){
            if(amount==0)return 1;
            return 0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int ans;
        if(amount<coins[i]){
            int coinNotTaken=helper(coins,i+1,amount,dp);
            ans=coinNotTaken;
        }
        else{
            int coinTaken=helper(coins,i,amount-coins[i],dp);
            int coinNotTaken=helper(coins,i+1,amount,dp);
            ans=coinTaken+coinNotTaken;
        }
        return dp[i][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(coins,0,amount,dp);
    }
};