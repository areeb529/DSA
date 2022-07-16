class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int area=0,offsets[]={0,1,0,-1,0};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int a=1;
                    queue<pair<int,int>> todo;
                    todo.push({i,j});
                    grid[i][j]=0;
                    while(!todo.empty()){
                    pair<int,int> f=todo.front();
                    todo.pop();
                    for(int k=0;k<4;k++){
                        int r=f.first+offsets[k];
                        int c=f.second+offsets[k+1];
                        if(r>=0&&r<m&&c>=0&&c<n&&grid[r][c]){
                            todo.push({r,c});
                            a++;
                            grid[r][c]=0;
                        }
                    }
                        
                  }
                    area=max(area,a);
                }
            }
        }
        return area;
    }
};