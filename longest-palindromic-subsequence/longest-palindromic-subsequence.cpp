class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int m=s.size();
        int n=m;
        int**dp=new int*[m+1];
        for(int i=0;i<=m;i++){
            dp[i]=new int[n+1];
        }
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[m-i]==t[n-j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};