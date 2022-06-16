class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> pN;
        int time=0;
        int numOranges=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    pN.push({i,j});
                }
                if(grid[i][j]==1){
                    numOranges++;
                }
            }
        }
        if(pN.size()==0&&numOranges)return -1;
        if(pN.size()==0&&numOranges==0)return 0;
        while(!pN.empty()){
           int N=pN.size();
            bool f=false;
            for(int i=0;i<N;i++){
                pair<int,int> front=pN.front();
                pN.pop();
                int x=front.first;
                int y=front.second;
                if(x+1<m&&grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    pN.push({x+1,y});
                    f=true;
                    numOranges--;
                }
                if(y+1<n&&grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    pN.push({x,y+1});
                    f=true;
                    numOranges--;
                }
                if(x-1>=0&&grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    pN.push({x-1,y});
                    f=true;
                    numOranges--;
                }
                if(y-1>=0&&grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    pN.push({x,y-1});
                    f=true;
                    numOranges--;
                }
            }
            if(f)time++;
        }
        if(numOranges==0)return time;
        else return -1;
    }
};