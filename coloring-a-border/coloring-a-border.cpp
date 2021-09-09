class Solution {
public:
    void dfs(vector<vector<int>>& grid,int m,int n,int i,int j,int color,int c,vector<vector<int>>&visited,vector<vector<int>>&ans){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]!=c||visited[i][j])return;
        visited[i][j]=true;
        if(i==0||i==m-1||j==0||j==n-1||grid[i-1][j]!=c||grid[i][j-1]!=c||grid[i+1][j]!=c||grid[i][j+1]!=c)
        ans[i][j]=color;
        dfs(grid,m,n,i-1,j,color,c,visited,ans);
        dfs(grid,m,n,i,j-1,color,c,visited,ans);
        dfs(grid,m,n,i+1,j,color,c,visited,ans);
        dfs(grid,m,n,i,j+1,color,c,visited,ans);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,false));
        vector<vector<int>>ans=grid;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==row&&j==col){
                    dfs(grid,m,n,i,j,color,grid[i][j],visited,ans);
                    break;
                }
            }
        }
        return ans;
    }
};