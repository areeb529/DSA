class Solution {
public:
bool dfs(vector<vector<char>>& board,int m,int n,int i,int j, string &word,int k){
        if(k==word.size()){
            return true;
        }
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='*'||board[i][j]!=word[k])return false;
        char temp=board[i][j];
        board[i][j]='*';
        bool ans=dfs(board,m,n,i-1,j,word,k+1)||
                 dfs(board,m,n,i,j-1,word,k+1)||
                 dfs(board,m,n,i+1,j,word,k+1)||
                 dfs(board,m,n,i,j+1,word,k+1);
        if(ans)return true;;
        board[i][j]=temp;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int i=0,j=0,k=0;
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 bool ans=false;
                 if(board[i][j]==word[k])
                 ans=dfs(board,m,n,i,j,word,k);
                 if(ans) return true;
             }
         }
        return false;
    }
};