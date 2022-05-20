class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=0,op2=0;
        if(i+1<m&&!obstacleGrid[i+1][j]){
            op1=helper(obstacleGrid,i+1,j,m,n,dp);
        }
        if(j+1<n&&!obstacleGrid[i][j+1]){
            op2=helper(obstacleGrid,i,j+1,m,n,dp);
        }
        return dp[i][j]=op1+op2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1])return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(obstacleGrid,0,0,m,n,dp);
    }
};