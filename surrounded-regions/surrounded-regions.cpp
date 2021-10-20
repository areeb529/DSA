class Solution {
public:
    void dfs(vector<vector<char>>& board,int m,int n,int i,int j){
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='X'||board[i][j]=='*')return;
        board[i][j]='*';
        dfs(board,m,n,i-1,j);
        dfs(board,m,n,i,j-1);
        dfs(board,m,n,i+1,j);
        dfs(board,m,n,i,j+1);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    if(board[i][j]=='O'){
                        dfs(board,m,n,i,j);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='*')board[i][j]='O';
            }
        }
    }
};