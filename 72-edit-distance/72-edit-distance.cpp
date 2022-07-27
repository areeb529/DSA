class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==m||j==n){
                    dp[i][j]=max(m-i,n-j);
                }
                else{
                    if(word1[i]==word2[j]){
                        dp[i][j]=dp[i+1][j+1];
                    }
                    else{
                        dp[i][j]=1+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
                    }
                }
            }
        }
        return dp[0][0];
    }
};