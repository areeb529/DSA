class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<bool>> &visited,int nonObstacles){
        nonObstacles--;
        if(grid[i][j]==2){
            if(nonObstacles==0)return 1;
            else return 0;
        }
        if(nonObstacles==0)return 0;
        //if(dp[i][j][nonObstacles]!=-1)return dp[i][j][nonObstacles];
        int op1=0,op2=0,op3=0,op4=0;
        visited[i][j]=true;
        if(i+1<m&&!visited[i+1][j]&&grid[i+1][j]>=0){
            op1=helper(grid,i+1,j,m,n,visited,nonObstacles);
        }
        if(j+1<n&&!visited[i][j+1]&&grid[i][j+1]>=0){
            op2=helper(grid,i,j+1,m,n,visited,nonObstacles);
        }
        if(i-1>=0&&!visited[i-1][j]&&grid[i-1][j]>=0){
            op3=helper(grid,i-1,j,m,n,visited,nonObstacles);
        }
        if(j-1>=0&&!visited[i][j-1]&&grid[i][j-1]>=0){
            op4=helper(grid,i,j-1,m,n,visited,nonObstacles);
        }
        visited[i][j]=false;
        return op1+op2+op3+op4;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int si=-1,sj=-1,ei=-1,ej=-1;
        int nonObstacles=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    si=i,sj=j;
                }
                if(grid[i][j]==2){
                    ei=i,ej=j;
                }
                if(grid[i][j]>=0)nonObstacles++;
            }
        }
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        //vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(nonObstacles+1,-1)));
        return helper(grid,si,sj,m,n,visited,nonObstacles);
    }
};