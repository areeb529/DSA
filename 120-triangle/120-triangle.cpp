class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle,int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==m-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=minimumTotal(triangle,m,n,i+1,j,dp);
        int op2=minimumTotal(triangle,m,n,i+1,j+1,dp);
        return dp[i][j]=triangle[i][j]+min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return minimumTotal(triangle,m,n,0,0,dp);
    }
};