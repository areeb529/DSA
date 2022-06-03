class Solution {
public:
    vector<vector<char>> mat;
    bool canPlace(vector<vector<char>>& board,char val,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(board[i][col]==val||board[row][i]==val)return false;
        }
        int subMatStartX=3*(row/3),subMatStartY=3*(col/3);
        for(int i=subMatStartX;i<subMatStartX+3;i++){
            for(int j=subMatStartY;j<subMatStartY+3;j++){
                if(board[i][j]==val)return false;
            }
        }
        return true;
    }
    void helper(vector<vector<char>>& board,int row,int col,int n){
        if(row==n){
            mat=board;
            return;
        }
        if(board[row][col]!='.')helper(board,row+(col+1)/n,(col+1)%n,n);
        else{
            for(char i='1';i<='9';i++){
                if(canPlace(board,i,row,col,n)){
                    board[row][col]=i;
                    helper(board,row+(col+1)/n,(col+1)%n,n);
                    board[row][col]='.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        helper(board,0,0,n);
        board=mat;
    }
};