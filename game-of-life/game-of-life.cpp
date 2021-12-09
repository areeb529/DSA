class Solution {
public:
    int liveCount(vector<vector<int>>& board,int x,int y,int m,int n){
        int cnt=0;
        int X,Y;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                X=x+i;
                Y=y+j;
                if((X==x&&Y==y)||X<0||X>=m||Y<0||Y>=n)continue;
                if(board[X][Y]>0)cnt++;
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=liveCount(board,i,j,m,n);
                if(board[i][j]){
                    if(cnt<2||cnt>3)board[i][j]=2;
                }
                else{
                    if(cnt==3)board[i][j]=-2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2)board[i][j]=0;
                else if(board[i][j]==-2)board[i][j]=1;
            }
        }
    }
};