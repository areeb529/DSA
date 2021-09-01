class Solution {
public:
    int helper(int &m,int &n,int i,int j,vector<vector<int>> &dp){
        if(i==m-1&&j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=0,down=0;
        if(i+1<m){
            if(dp[i+1][j]!=-1)down=dp[i+1][j];
            else down=helper(m,n,i+1,j,dp);
        }
        if(j+1<n){
            if(dp[i][j+1]!=-1)right=dp[i][j+1];
            else right=helper(m,n,i,j+1,dp);
        }
            
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m,n,0,0,dp);
    }
};