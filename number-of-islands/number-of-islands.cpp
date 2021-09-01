class Solution {
public:
    void dfs(vector<vector<char>>& grid,int m,int n,vector<vector<int>> &visited,int i,int j){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]=='0'||visited[i][j])return;
        visited[i][j]=1;
        dfs(grid,m,n,visited,i-1,j);
        dfs(grid,m,n,visited,i,j-1);
        dfs(grid,m,n,visited,i+1,j);
        dfs(grid,m,n,visited,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    ct++;
                    dfs(grid,m,n,visited,i,j);
                }
            }
        }
        return ct;
    }
};