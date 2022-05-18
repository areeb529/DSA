class Solution {
public:
    void dfs(vector<vector<int>>& image,int x,int y,int origColor,int newColor,int m,int n){
        if(x<0||x>=m||y<0||y>=n||image[x][y]!=origColor)return;
        image[x][y]=newColor;
        dfs(image,x+1,y,origColor,newColor,m,n);
        dfs(image,x,y+1,origColor,newColor,m,n);
        dfs(image,x-1,y,origColor,newColor,m,n);
        dfs(image,x,y-1,origColor,newColor,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)return image;
        int m=image.size();
        int n=image[0].size();
        dfs(image,sr,sc,image[sr][sc],newColor,m,n);
        return image;
    }
};