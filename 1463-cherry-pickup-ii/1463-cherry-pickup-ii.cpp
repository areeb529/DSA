class Solution {
public:
    int maxPathSum(vector<vector<int>>& grid,int i,int j,int k,int m,int n,vector<vector<vector<int>>> &dp){
        if(j<0||j>=n||k<0||k>=n)return INT_MIN;
        if(i==m-1){
            if(j==k){
                return grid[i][j];
            }
            else{
                return grid[i][j]+grid[i][k];
            }
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int ans=0;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                ans=max(ans,maxPathSum(grid,i+1,j+x,k+y,m,n,dp));
            }
        }
        if(j==k){
         return dp[i][j][k]=grid[i][j]+ans;   
        }
        else{
            return dp[i][j][k]=grid[i][j]+grid[i][k]+ans;
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return maxPathSum(grid,0,0,n-1,m,n,dp);
    }
};