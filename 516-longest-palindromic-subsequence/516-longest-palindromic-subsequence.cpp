class Solution {
public:
    int lcs(string &s,int i,string &p,int j,vector<vector<int>> &dp){
        if(i==s.size()||j==p.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j]){
            return dp[i][j]=1+lcs(s,i+1,p,j+1,dp);
        }
        else{
            return dp[i][j]=max(lcs(s,i+1,p,j,dp),lcs(s,i,p,j+1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string p=s;
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        reverse(p.begin(),p.end());
        return lcs(s,0,p,0,dp);
    }
};