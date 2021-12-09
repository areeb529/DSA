class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m=word1.size(),n=word2.size();
        vector<int> dp(n+1);
        for(int i=m;i>=0;i--){
            int prev;
            for(int j=n;j>=0;j--){
                int temp=dp[j];
                if(i==m||j==n){
                    dp[j]=max(m-i,n-j);
                }
                else if(word1[i]==word2[j]){
                    dp[j]=prev;
                }
                else{
                    dp[j]=1+min(dp[j],dp[j+1]);
                }
                prev=temp;;
            }
        }
        return dp[0];
    }
};