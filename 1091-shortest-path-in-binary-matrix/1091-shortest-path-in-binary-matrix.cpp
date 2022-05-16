class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]||grid[n-1][n-1])return -1;
        queue<pair<int,int>> pN;
        vector<vector<int>> visited(n,vector<int>(n,false));
        pN.push({0,0});
        visited[0][0]=true;
        int ans=0;
        bool f=false;
        while(!pN.empty()){
            int N=pN.size();
            ans++;
            for(int i=0;i<N;i++){
                pair<int,int> front=pN.front();
                int X=front.first;
                int Y=front.second;
                if(X==n-1&&Y==n-1){
                    f=true;
                    break;
                }
                pN.pop();
                if(X+1<n&&!grid[X+1][Y]&!visited[X+1][Y]){
                    pN.push({X+1,Y});
                    visited[X+1][Y]=true;
                }
                if(Y+1<n&&!grid[X][Y+1]&&!visited[X][Y+1]){
                    pN.push({X,Y+1});
                    visited[X][Y+1]=true;
                }
                if(X-1>=0&&!grid[X-1][Y]&&!visited[X-1][Y]){
                    pN.push({X-1,Y});
                    visited[X-1][Y]=true;
                }
                if(Y-1>=0&&!grid[X][Y-1]&&!visited[X][Y-1]){
                    pN.push({X,Y-1});
                    visited[X][Y-1];
                }
                if(X+1<n&&Y+1<n&&!grid[X+1][Y+1]&&!visited[X+1][Y+1]){
                    pN.push({X+1,Y+1});
                    visited[X+1][Y+1]=true;
                }
                if(X+1<n&&Y-1>=0&&!grid[X+1][Y-1]&&!visited[X+1][Y-1]){
                    pN.push({X+1,Y-1});
                    visited[X+1][Y-1];
                }
                if(X-1>=0&&Y+1<n&&!grid[X-1][Y+1]&&!visited[X-1][Y+1]){
                    pN.push({X-1,Y+1});
                    visited[X-1][Y+1]=true;
                }
                if(X-1>=0&&Y-1>=0&&!grid[X-1][Y-1]&&!visited[X-1][Y-1]){
                    pN.push({X-1,Y-1});
                    visited[X-1][Y-1]=true;
                }
            }
            if(f)break;
        }
        
        if(!f)return -1;
        return ans;
    }
};