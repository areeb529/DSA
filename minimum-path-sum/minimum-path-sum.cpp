class Solution {
public:
    // int helper(vector<vector<int>>& grid,int i,int j){
    //     int m=grid.size(),n=grid[0].size();
    //     if(i==m-1&&j==n-1)return grid[i][j];
    //     if(i==m||j==n)return INT_MAX;
    //     int a=INT_MAX,b=INT_MAX;
    //     a=helper(grid,i+1,j);
    //     b=helper(grid,i,j+1);
    //     return grid[i][j]+min(a,b);
    // }
    int helper(vector<vector<int>>& grid,int i,int j,int**dp){
        int m=grid.size(),n=grid[0].size();
        if(i==m-1&&j==n-1)return grid[i][j];
        if(i==m||j==n)return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=INT_MAX,b=INT_MAX;
        a=helper(grid,i+1,j,dp);
        b=helper(grid,i,j+1,dp);
        dp[i][j]=grid[i][j]+min(a,b);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int**dp=new int*[m];
        for(int i=0;i<m;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        return helper(grid,0,0,dp);
    }
};