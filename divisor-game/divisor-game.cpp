class Solution {
public:
    bool divisorGame(int N,vector<int>&dp){
        if(dp[N]!=-1)return dp[N];
        for(int i=1;i<N;i++){
            if(N%i==0){
                bool ans;
                if(dp[N-i]!=-1)ans=dp[N-i];
                else
                ans=divisorGame(N-i,dp);
                if(!ans){
                    dp[N]=1;
                    return true;
                }
            }
        }
        dp[N]=0;
        return false;
    }
    bool divisorGame(int N) {
        vector<int>dp(N+1,-1); 
        return divisorGame(N,dp);
    }
};