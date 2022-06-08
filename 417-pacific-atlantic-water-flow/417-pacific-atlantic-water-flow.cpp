class Solution {
public:
    bool isValid(vector<vector<int>>& heights,int sx,int sy,int x,int y,int m,int n,vector<vector<bool>> &visited){
        if(x<0||x>=m||y<0||y>=n||visited[x][y]||heights[sx][sy]>heights[x][y])return false;
        else return true;
    }
    void dfs(vector<vector<int>>& heights,int x,int y,int m,int n,vector<vector<bool>> &visited){
        visited[x][y]=true;
        vector<int> dx={-1,0,1,0,-1};
        for(int i=0;i<4;i++){
            if(isValid(heights,x,y,x+dx[i],y+dx[i+1],m,n,visited))
            dfs(heights,x+dx[i],y+dx[i+1],m,n,visited);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> visitPacific(m,vector<bool>(n,false));
        vector<vector<bool>> visitAtlantic(m,vector<bool>(n,false));
        for(int j=0;j<n;j++){
            if(!visitPacific[0][j])
            dfs(heights,0,j,m,n,visitPacific);
        }
        for(int i=1;i<m;i++){
            if(!visitPacific[i][0])
            dfs(heights,i,0,m,n,visitPacific);
        }
        for(int j=0;j<n;j++){
            if(!visitAtlantic[m-1][j])
            dfs(heights,m-1,j,m,n,visitAtlantic);
        }
        for(int i=0;i<m-1;i++){
            if(!visitAtlantic[i][n-1])
            dfs(heights,i,n-1,m,n,visitAtlantic);
        }
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visitPacific[i][j]&&visitAtlantic[i][j])res.push_back({i,j});
            }
        }
        return res;
    }
};