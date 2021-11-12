class Solution {
public:
    // int numTrees(int n,vector<int> &dp){
    //     if(n==0||n==1)return 1;
    //     if(dp[n]!=-1)return dp[n];
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         int left=numTrees(i,dp);
    //         int right=numTrees(n-i-1,dp);
    //         ans+=left*right;
    //     }
    //     return dp[n]=ans;
    // }
    int numTrees(int n) {
        // vector<int> dp(n+1,-1);
        // return numTrees(n,dp);
        if(n==0||n==1)return 1;
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;i++){
            int ans=0;
            for(int j=0;j<i;j++){
                int l=dp[j];
                int r=dp[i-j-1];
                ans+=l*r;
            }
            dp[i]=ans;
        }
        return dp[n];
    }
};