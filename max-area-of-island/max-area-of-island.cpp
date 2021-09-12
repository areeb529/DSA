class Solution {
public:
    void dfs(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<bool>>& visited,int &ct){
        if(i<0||i>=m||j<0||j>=n||visited[i][j]||!grid[i][j])return;
        visited[i][j]=true;
        ct++;
        dfs(grid,m,n,i-1,j,visited,ct);
        dfs(grid,m,n,i,j-1,visited,ct);
        dfs(grid,m,n,i+1,j,visited,ct);
        dfs(grid,m,n,i,j+1,visited,ct);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]&&!visited[i][j]){
                  int ct=0;
                    dfs(grid,m,n,i,j,visited,ct);
                    res=max(res,ct);
                }
            }
        }
        return res;
    }
};