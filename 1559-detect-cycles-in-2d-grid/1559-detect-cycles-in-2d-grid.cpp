class Solution {
public:
    bool dfs(vector<vector<char>>&grid,int m,int n,int i,int j,int pi,int pj,int sv,vector<vector<bool>> &visited){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]!=sv)return false;
        if(visited[i][j])return true;
        visited[i][j]=true;
        bool op1=false,op2=false,op3=false,op4=false;
        if(!(i+1==pi&&j==pj))
        op1=dfs(grid,m,n,i+1,j,i,j,sv,visited);
        if(!(i==pi&&j+1==pj))
        op2=dfs(grid,m,n,i,j+1,i,j,sv,visited);
        if(!(i-1==pi&&j==pj))
        op3=dfs(grid,m,n,i-1,j,i,j,sv,visited);
        if(!(i==pi&&j-1==pj))
        op4=dfs(grid,m,n,i,j-1,i,j,sv,visited);
        if(op1||op2||op3||op4)return true;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool f=false;
                if(!visited[i][j])
                f=dfs(grid,m,n,i,j,-1,-1,grid[i][j],visited);
                if(f)return true;
            }
        }
        return false;
    }
};