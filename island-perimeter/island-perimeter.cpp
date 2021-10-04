class Solution {
public:
    int ct=0;
    void dfs(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<int>>& visited){
        if(i<0||i>=m||j<0||j>=n||!grid[i][j]){
            ct++;
            return;
        }
        if(visited[i][j])return;
        visited[i][j]=1;
        dfs(grid,m,n,i-1,j,visited);
        dfs(grid,m,n,i,j-1,visited);
        dfs(grid,m,n,i+1,j,visited);
        dfs(grid,m,n,i,j+1,visited);
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        bool f=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    f=true;
                    dfs(grid,m,n,i,j,visited);
                    break;
                }
            }
            if(f)
            break;
        }
        return ct;
        
    }
};