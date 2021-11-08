class Solution {
public:
    int numTrees(int n,vector<int> &dp){
        if(n==0||n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=0;i<n;i++){
            int left=numTrees(i,dp);
            int right=numTrees(n-i-1,dp);
            ans+=left*right;
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return numTrees(n,dp);
    }
};