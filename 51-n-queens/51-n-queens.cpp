class Solution {
public:
    vector<vector<string>> res;
    bool canPlace(vector<string> &board,int row,int col,int n,vector<int> &upperCol,vector<int> &upperDiag,vector<int>&lowerDiag){
        if(upperCol[col]==1||upperDiag[n-1-row+col]==1||lowerDiag[row+col]==1)return false;
        else{
            upperCol[col]=1;
            upperDiag[n-1-row+col]=1;
            lowerDiag[row+col]=1;
            return true;
        }
    }
    void placeQueens(vector<string> &board,int row,int n,vector<int> &upperCol,vector<int> &upperDiag,vector<int>&lowerDiag){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(canPlace(board,row,col,n,upperCol,upperDiag,lowerDiag)){
                board[row][col]='Q';
                placeQueens(board,row+1,n,upperCol,upperDiag,lowerDiag);
                board[row][col]='.';
                upperCol[col]=0;
                upperDiag[n-1-row+col]=0;
                lowerDiag[row+col]=0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<int> upperCol(n,0);
        vector<int> upperDiag(2*n-1,0);
        vector<int> lowerDiag(2*n-1,0);
        placeQueens(board,0,n,upperCol,upperDiag,lowerDiag);
        return res;
    }
};