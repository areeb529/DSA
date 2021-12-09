class Solution {
public:
    int helper(string &word1,string &word2,int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==m||j==n){
            return max(m-i,n-j);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=helper(word1,word2,i+1,j+1,m,n,dp);
        }
        else{
            int op1=helper(word1,word2,i+1,j,m,n,dp);
            int op2=helper(word1,word2,i,j+1,m,n,dp);
            return dp[i][j]=1+min(op1,op2);
        }
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(word1,word2,0,0,m,n,dp);
    }
};