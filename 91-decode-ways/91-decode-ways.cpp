class Solution {
public:
    int helper(string &s,int i,vector<int> &dp){
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        int op1=0,op2=0;
        op1=helper(s,i+1,dp);
        if(i+1<s.size()&&stoi(s.substr(i,2))<=26)op2=helper(s,i+2,dp);
        return dp[i]=op1+op2;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return helper(s,0,dp);
    }
};