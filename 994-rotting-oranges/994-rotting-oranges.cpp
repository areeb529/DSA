class Solution {
public:
    bool isValid(vector<vector<int>> &grid,int row,int col,int m,int n){
        if(row<0||row>=m||col<0||col>=n||grid[row][col]!=1)return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> pN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)pN.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }
        int time=0;
        while(!pN.empty()&&fresh){
            int N=pN.size();
            for(int i=0;i<N;i++){
                pair<int,int> front=pN.front();
                pN.pop();
                int row=front.first;
                int col=front.second;
                if(isValid(grid,row+1,col,m,n)){
                    grid[row+1][col]=2;
                    pN.push({row+1,col});
                    fresh--;
                }
                if(isValid(grid,row,col+1,m,n)){
                    grid[row][col+1]=2;
                    pN.push({row,col+1});
                    fresh--;
                }
                if(isValid(grid,row-1,col,m,n)){
                    grid[row-1][col]=2;
                    pN.push({row-1,col});
                    fresh--;
                }
                if(isValid(grid,row,col-1,m,n)){
                    grid[row][col-1]=2;
                    pN.push({row,col-1});
                    fresh--;
                }
            }
            time++;
        }
        if(fresh)return -1;
        return time;
    }
};