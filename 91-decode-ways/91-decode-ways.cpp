class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1);
        dp[n]=1;
        //return helper(s,0,dp);
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')dp[i]=0;
            else{
                int op1=0,op2=0;
                op1=dp[i+1];
                if(i+1<n&&stoi(s.substr(i,2))<=26)op2=dp[i+2];
                dp[i]=op1+op2;
            }
        }
        return dp[0];
    }
};