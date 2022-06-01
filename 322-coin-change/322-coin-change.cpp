class Solution {
public:
    int helper(vector<int>& coins,int i,int n,int amount,vector<vector<int>> &dp){
        if(i==n){
            if(amount==0)return 0;
            return -1;
        }
        if(dp[i][amount]!=-2)return dp[i][amount];
        int op1=-1,op2=-1;
        if(amount>=coins[i]){
            int temp=helper(coins,i,n,amount-coins[i],dp);
            if(temp==-1)op1=-1;
            else op1=1+temp;
        }
        op2=helper(coins,i+1,n,amount,dp);
        if(op1==-1||op2==-1)return dp[i][amount]=max(op1,op2);
        else return dp[i][amount]=min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-2));
        return helper(coins,0,n,amount,dp);
    }
};