class Solution {
public:
    void dfs(vector<vector<int>>& image,int x,int y,int origColor,int m,int n,vector<vector<bool>> &visited){
        if(x<0||x>=m||y<0||y>=n||image[x][y]!=origColor||visited[x][y])return;
        visited[x][y]=true;
        dfs(image,x+1,y,origColor,m,n,visited);
        dfs(image,x,y+1,origColor,m,n,visited);
        dfs(image,x-1,y,origColor,m,n,visited);
        dfs(image,x,y-1,origColor,m,n,visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)return image;
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        dfs(image,sr,sc,image[sr][sc],m,n,visited);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]){
                    image[i][j]=newColor;
                }
            }
        }
        return image;
    }
};