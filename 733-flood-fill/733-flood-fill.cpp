class Solution {
public:
   void helper(vector<vector<int>>& image, int sr, int sc,int m,int n,int color, int newColor){
       if(sr<0||sr>=m||sc<0||sc>=n||image[sr][sc]!=color)return;
       image[sr][sc]=newColor;
       helper(image,sr+1,sc,m,n,color,newColor);
       helper(image,sr,sc+1,m,n,color,newColor);
       helper(image,sr-1,sc,m,n,color,newColor);
       helper(image,sr,sc-1,m,n,color,newColor);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        int color=image[sr][sc];
        if(color==newColor)return image;
        helper(image,sr,sc,m,n,color,newColor);
        return image;
    }
};