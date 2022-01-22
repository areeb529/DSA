class Solution {
public:
    bool winnerSquareGame(int n,vector<int> &dp){
        if(n==0)return false;
        if(n==1)return true;
        if(dp[n]!=-1)return dp[n];
        bool f=true;
        for(int i=1;i*i<=n;i++){
            f=winnerSquareGame(n-i*i,dp);
            if(!f)return dp[n]=true;
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return winnerSquareGame(n,dp);
    }
};