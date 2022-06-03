class Solution {
public:
    bool canPlace(vector<vector<char>>& board,char val,int row,int col){
        for(int i=0;i<9;i++){
            if(board[i][col]==val||board[row][i]==val)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)return false;
        }
        return true;
    }
    bool helper(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(canPlace(board,c,i,j)){
                            board[i][j]=c;
                            if(helper(board)==true)return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        bool isSolved=helper(board);
    }
};