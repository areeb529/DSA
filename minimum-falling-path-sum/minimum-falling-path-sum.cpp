class Solution {
public:
    int helper(vector<vector<int>>& matrix,int m,int n,int i,int j,vector<vector<int>> &dp){
        if(j<0||j>=n)return INT_MAX;
        if(i==m-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=-10001)return dp[i][j];
        int op1=helper(matrix,m,n,i+1,j-1,dp);
        int op2=helper(matrix,m,n,i+1,j,dp);
        int op3=helper(matrix,m,n,i+1,j+1,dp);
        return dp[i][j]=matrix[i][j]+min(op1,min(op2,op3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-10001));
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,helper(matrix,m,n,0,j,dp));
        }
        return ans;
    }
};