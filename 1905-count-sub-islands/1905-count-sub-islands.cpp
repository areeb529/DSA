class Solution {
public:
    void helper(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int x,int y,int m,int n,bool &isSubIsland){
        if(x<0||x>=m||y<0||y>=n||grid2[x][y]==0) return;
        grid2[x][y]=0;
        if(grid1[x][y]==0)isSubIsland=false;
        helper(grid1,grid2,x+1,y,m,n,isSubIsland);
        helper(grid1,grid2,x,y+1,m,n,isSubIsland);
        helper(grid1,grid2,x-1,y,m,n,isSubIsland);
        helper(grid1,grid2,x,y-1,m,n,isSubIsland);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    bool isSubIsland=true;
                    helper(grid1,grid2,i,j,m,n,isSubIsland);
                    if(isSubIsland)res++;
                }
            }
        }
        return res;
    }
};