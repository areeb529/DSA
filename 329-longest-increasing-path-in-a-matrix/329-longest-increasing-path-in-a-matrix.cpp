class Solution {
public:
    int helper(vector<vector<int>>& matrix,int i,int j,int m,int n,vector<vector<bool>> &visited,vector<vector<int>> &dp){
        if(dp[i][j]!=-1)return dp[i][j];
        visited[i][j]=true;
        int op1=0,op2=0,op3=0,op4=0;
        if(i+1<m&&!visited[i+1][j]&&matrix[i][j]<matrix[i+1][j])op1=1+helper(matrix,i+1,j,m,n,visited,dp);
        if(j+1<n&&!visited[i][j+1]&&matrix[i][j]<matrix[i][j+1])op2=1+helper(matrix,i,j+1,m,n,visited,dp);
        if(i-1>=0&&!visited[i-1][j]&&matrix[i][j]<matrix[i-1][j])op3=1+helper(matrix,i-1,j,m,n,visited,dp);
        if(j-1>=0&&!visited[i][j-1]&&matrix[i][j]<matrix[i][j-1])op4=1+helper(matrix,i,j-1,m,n,visited,dp);
        visited[i][j]=false;
        int ans=1;
        ans=max(ans,max(max(op1,op2),max(op3,op4)));
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,helper(matrix,i,j,m,n,visited,dp));
            }
        }
        return ans;
    }
};