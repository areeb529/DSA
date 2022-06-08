class Solution {
public:
    bool dfs(vector<vector<int>>& heights,int x,int y,int m,int n,bool &pacific,bool &atlantic,vector<vector<bool>> &visited){
        if(x==0||y==0){
            pacific=true;
        }
        if(x==m-1||y==n-1){
            atlantic=true;
        }
        if(pacific&&atlantic)return true;
        visited[x][y]=true;
        bool ans1=false,ans2=false,ans3=false,ans4=false;
        if(x-1>=0&&!visited[x-1][y]&&heights[x][y]>=heights[x-1][y]){
            ans1=dfs(heights,x-1,y,m,n,pacific,atlantic,visited);
        }
        if(y-1>=0&&!visited[x][y-1]&&heights[x][y]>=heights[x][y-1]){
            ans2=dfs(heights,x,y-1,m,n,pacific,atlantic,visited);
        }
        if(x+1<m&&!visited[x+1][y]&&heights[x][y]>=heights[x+1][y]){
            ans3=dfs(heights,x+1,y,m,n,pacific,atlantic,visited);
        }
        if(y+1<n&&!visited[x][y+1]&&heights[x][y]>=heights[x][y+1]){
            ans4=dfs(heights,x,y+1,m,n,pacific,atlantic,visited);
        }
        visited[x][y]=false;
        if(ans1||ans2||ans3||ans4)return true;
        else return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool pacific=false,atlantic=false;
                bool ans=false;
                ans=dfs(heights,i,j,m,n,pacific,atlantic,visited);
                if(ans)res.push_back({i,j});
            }
        }
        return res;
    }
};