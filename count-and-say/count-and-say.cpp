class Solution {
public:
    string countAndSay(int n,vector<string> &dp) {
        if(n==1){
            return "1";
        }
        if(dp[n]!="#")return dp[n];
        
        string s=countAndSay(n-1,dp);
        int ct=1;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1||s[i]!=s[i+1]){
                char temp=ct+'0';
                ans.push_back(temp);
                ans.push_back(s[i]);
                ct=1;
            }
            else{
                ct++;
            }
        }
        return dp[n]=ans;
    }
    string countAndSay(int n) {
        vector<string> dp(n+1,"#");
        return countAndSay(n,dp);
    }
};