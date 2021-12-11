class Solution {
public:
    int mod=1e9+7;
    int helper(int d, int f, int target,vector<vector<int>> &dp){
        if(d==0){
            if(target==0)return 1;
            else return 0;
        }
        if(dp[d][target]!=-1)return dp[d][target];
        int ans=0;
        for(int i=1;i<=f;i++){
            if(target-i>=0)
            ans=(ans+helper(d-1,f,target-i,dp))%mod;
            else break;
        }
        return dp[d][target]=ans;
    }
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d+1,vector<int>(target+1,-1));
        return helper(d,f,target,dp);
    }
};