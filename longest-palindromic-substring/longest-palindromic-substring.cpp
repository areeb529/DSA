class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,1));
        string ans=s.substr(0,1);
        int maxL=1;
        for(int k=1;k<n;k++){
            for(int i=0;i+k<n;i++){
                if(s[i]==s[i+k]){
                    dp[i][i+k]=dp[i+1][i+k-1]&1;
                    if(dp[i][i+k]&&k+1>maxL){
                        maxL=k+1;
                        ans=s.substr(i,k+1);
                    }
                }
                else{
                    dp[i][i+k]=0;
                }
            }
        }
        return ans;
    }
};