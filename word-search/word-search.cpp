class Solution {
public:
bool dfs(vector<vector<char>>& board,int m,int n,int i,int j, string &word,int k,vector<vector<bool>>& visited){
        if(k==word.size()){
            return true;
        }
        if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[k]||visited[i][j])return false;
        visited[i][j]=true;
        bool opt1=dfs(board,m,n,i-1,j,word,k+1,visited);
        if(opt1)return true;
        bool opt2=dfs(board,m,n,i,j-1,word,k+1,visited);
        if(opt2)return true;
        bool opt3=dfs(board,m,n,i+1,j,word,k+1,visited);
        if(opt3)return true;
        bool opt4=dfs(board,m,n,i,j+1,word,k+1,visited);
        if(opt4)return true;;
        visited[i][j]=false;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int i=0,j=0,k=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 bool ans=false;
                 if(board[i][j]==word[0])
                 ans=dfs(board,m,n,i,j,word,k,visited);
                 if(ans) return true;
             }
         }
        return false;
    }
};