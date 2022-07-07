class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size();
        if(m+n!=s3.size())return false;
        vector<int> dp(n+1,0);
        for(int i=m;i>=0;i--){
            
            for(int j=n;j>=0;j--){
                int k=i+j;
                if(k==s3.size()){
                    dp[j]=1;
                }
                else if(i<m&&s1[i]==s3[k]&&j<n&&s2[j]==s3[k]){
                    dp[j]=dp[j]||dp[j+1];
                }
                else if(i<m&&s1[i]==s3[k]){
                    dp[j]=dp[j];
                }
                else if(j<n&&s2[j]==s3[k]){
                    dp[j]=dp[j+1];
                }
                else{
                    dp[j]=0;
                }
            }
        }
        return dp[0];
    }
};