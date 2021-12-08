class Solution {
public:
    
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int cnt=0;
        for(int k=0;k<n;k++){
            for(int i=0,j=i+k;i<=j;i++){
                if(s[i]==s[j]){
                    if(i==j||j-i==1){
                        dp[i][j]=1;
                        cnt++;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                        if(dp[i][j])cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};