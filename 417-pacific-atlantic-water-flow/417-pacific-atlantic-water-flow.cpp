class Solution {
public:
    bool isValid(vector<vector<int>>& heights,int sx,int sy,int x,int y,int m,int n,vector<vector<int>> &visited){
        if(x<0||x>=m||y<0||y>=n||visited[x][y]==0||heights[sx][sy]<heights[x][y])return false;
        else return true;
    }
    bool dfs(vector<vector<int>>& heights,int x,int y,int m,int n,vector<vector<int>> &visited,bool ocean){
        if(ocean){
            if(x==0||y==0||visited[x][y]==1){
                visited[x][y]=true;
                return true;
            }
        }
        else{
            if(x==m-1||y==n-1||visited[x][y]==1){
                visited[x][y]=true;
                return true;
            }
        }
        visited[x][y]=0;
        vector<int> dx={-1, 0, 1, 0, -1};
        bool ans=false;
        for(int i=0;i<4;i++){
            if(isValid(heights,x,y,x+dx[i],y+dx[i+1],m,n,visited)){
                ans=dfs(heights,x+dx[i],y+dx[i+1],m,n,visited,ocean);
                if(ans)break;
            }
        }
        if(ans){
            visited[x][y]=1;
            return true;
        }
        visited[x][y]=-1;
        return false;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> visitPacific(m,vector<int>(n,-1));
        vector<vector<int>> visitAtlantic(m,vector<int>(n,-1));
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool cond1=false,cond2=false;
                if(visitPacific[i][j]==-1)
                cond1=dfs(heights,i,j,m,n,visitPacific,true);
                else if(visitPacific[i][j]==1)cond1=true;
                if(visitAtlantic[i][j]==-1)
                cond2=dfs(heights,i,j,m,n,visitAtlantic,false);
                else if(visitAtlantic[i][j]==1)cond2=true;
                if(cond1&&cond2)res.push_back({i,j});
            }
        }
        return res;
    }
};