class Solution {
public:
    bool helper(string &s1,int i,string &s2,int j,string &s3,vector<vector<int>> &dp){
        if(dp[i][j]!=-1)return dp[i][j];
        int k=i+j;
        if(k==s3.size()){
            return dp[i][j]=1;
        }
        else if(i<s1.size()&&s1[i]==s3[k]&&j<s2.size()&&s2[j]==s3[k]){
            return dp[i][j]=helper(s1,i+1,s2,j,s3,dp)||helper(s1,i,s2,j+1,s3,dp);
        }
        else if(i<s1.size()&&s1[i]==s3[k]){
            return dp[i][j]=helper(s1,i+1,s2,j,s3,dp);
        }
        else if(j<s2.size()&&s2[j]==s3[k]){
            return dp[i][j]=helper(s1,i,s2,j+1,s3,dp);
        }
        else{
            return dp[i][j]=0;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size();
        if(m+n!=s3.size())return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(s1,0,s2,0,s3,dp);
    }
};