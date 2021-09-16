class Solution {
public:
    int helper(vector<int>& coins, int amount,int i,vector<vector<int>> &dp){
        if(amount==0){
           return 0; 
        }
        if(i==coins.size()){
            return -1;
        }
        if(dp[i][amount]!=-2)return dp[i][amount];
        int a=-1,b=-1;
        if(coins[i]<=amount){
            int temp=helper(coins,amount-coins[i],i,dp);
            if(temp!=-1)a=1+temp;
        }
        b=helper(coins,amount,i+1,dp);
        if(a!=-1&&b!=-1)return dp[i][amount]=min(a,b);
        else return dp[i][amount]=max(a,b);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int m=amount;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-2));
        return helper(coins,amount,0,dp);
    }
};