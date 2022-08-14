class Solution {
public:
    bool helper(string &s1,int i,string &s2,int j,string &s3,int k,vector<vector<int>> &dp){
        if(k==s3.size()){
            if(i==s1.size()&&j==s2.size())return true;
            else return false;
        }
        if(i==s1.size()&&j==s2.size()){
            return false;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool op1=false,op2=false;
        if(i<s1.size()&&s1[i]==s3[k]){
            op1=helper(s1,i+1,s2,j,s3,k+1,dp);
        }
        if(j<s2.size()&&s2[j]==s3[k]){
            op2=helper(s1,i,s2,j+1,s3,k+1,dp);
        }
        return dp[i][j]=op1||op2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size(),k=s3.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       return helper(s1,0,s2,0,s3,0,dp);
    }
};