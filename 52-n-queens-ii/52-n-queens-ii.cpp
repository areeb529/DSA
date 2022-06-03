class Solution {
public:
    int res=0;
    bool canPlace(vector<string> &board,int row,int col,int n){
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q')return false;
        }
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    void placeQueens(vector<string> &board,int row,int n){
        if(row==n){
            res++;
            return;
        }
        for(int col=0;col<n;col++){
            if(canPlace(board,row,col,n)){
                board[row][col]='Q';
                placeQueens(board,row+1,n);
                board[row][col]='.';
            }
        }
        
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        placeQueens(board,0,n);
        return res;
    }
};