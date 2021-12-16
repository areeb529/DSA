class Solution {
public:
    bool isValid(int m,int n,int i,int j,vector<vector<bool>>& visited){
        if(i<0||i>=m||j<0||j>=n||visited[i][j])return false;
        return true;
    }
    bool dfs(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<bool>>& visited){
        if(i==m-1&&j==n-1)return true;
        
        visited[i][j]=true;
        bool ans=false;
        if(grid[i][j]==1){
            if(isValid(m,n,i,j+1,visited)&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)){
                ans=dfs(grid,m,n,i,j+1,visited);
                if(ans)return true;
            }
            if(isValid(m,n,i,j-1,visited)&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)){
                return dfs(grid,m,n,i,j-1,visited);
            }
        }
        else if(grid[i][j]==2){
            if(isValid(m,n,i-1,j,visited)&&(grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4)){
                ans=dfs(grid,m,n,i-1,j,visited);
                if(ans)return true;
            }
            if(isValid(m,n,i+1,j,visited)&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6)){
                return dfs(grid,m,n,i+1,j,visited);
            }
        }
        else if(grid[i][j]==3){
            if(isValid(m,n,i,j-1,visited)&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)){
                ans=dfs(grid,m,n,i,j-1,visited);
                if(ans)return true;
            }
            if(isValid(m,n,i+1,j,visited)&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6)){
                return dfs(grid,m,n,i+1,j,visited);
            }
        }
        else if(grid[i][j]==4){
            if(isValid(m,n,i,j+1,visited)&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)){
                ans=dfs(grid,m,n,i,j+1,visited);
                if(ans)return true;
            }
            if(isValid(m,n,i+1,j,visited)&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6)){
                return dfs(grid,m,n,i+1,j,visited);
            }
        }
        else if(grid[i][j]==5){
            if(isValid(m,n,i-1,j,visited)&&(grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4)){
                ans=dfs(grid,m,n,i-1,j,visited);
                if(ans)return true;
            }
            if(isValid(m,n,i,j-1,visited)&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)){
                return dfs(grid,m,n,i,j-1,visited);
            }
        }
        else{
            if(isValid(m,n,i,j+1,visited)&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)){
                ans=dfs(grid,m,n,i,j+1,visited);
                if(ans)return true;
            }
            if(isValid(m,n,i-1,j,visited)&&(grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==5)){
                return dfs(grid,m,n,i-1,j,visited);
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(grid,m,n,0,0,visited);
    }
};