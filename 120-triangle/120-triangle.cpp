class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                if(i==m-1)dp[i][j]=triangle[i][j];
                else dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};