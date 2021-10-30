class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> adj;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==2){
                   adj.push({i,j});
               }
                else if(grid[i][j]==1)fresh++;
            }
        }
         int t=0;
        while(!adj.empty()){
            int len=adj.size();
            if(fresh)t++;
            for(int i=0;fresh&&i<len;i++){
                pair<int,int> front=adj.front();
                adj.pop();
                int x=front.first;
                int y=front.second;
                if(x-1>=0&&grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    fresh--;
                    adj.push({x-1,y});
                }
                if(y-1>=0&&grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    fresh--;
                    adj.push({x,y-1});
                }
                if(x+1<m&&grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    fresh--;
                    adj.push({x+1,y});
                }
                if(y+1<n&&grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    fresh--;
                    adj.push({x,y+1});
                }
            }
            if(!fresh)break;
        }
        return fresh==0? t: -1;
    }
};