class Solution {
public:
    int helper(string &word1,int i,int m, string &word2,int j,int n,vector<vector<int>> &dp){
        if(i==m||j==n){
            return max(m-i,n-j);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=helper(word1,i+1,m,word2,j+1,n,dp);
        }
        else{
            int op1=1+helper(word1,i+1,m,word2,j,n,dp);
            int op2=1+helper(word1,i,m,word2,j+1,n,dp);
            int op3=1+helper(word1,i+1,m,word2,j+1,n,dp);
            return dp[i][j]=min(op1,min(op2,op3));
        }
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(word1,0,m,word2,0,n,dp);
    }
};