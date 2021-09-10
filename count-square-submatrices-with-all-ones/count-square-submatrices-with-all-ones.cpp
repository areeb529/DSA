class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int s=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]==0){
                    dp[i][j]=0;
                }
                else{
                    int a=dp[i-1][j];
                    int b=dp[i-1][j-1];
                    int c=dp[i][j-1];
                    dp[i][j]=1+min(a,min(b,c));
                }
               s+=dp[i][j];
            }
        }
        return s;
        // int m=matrix.size();
        // int n=matrix[0].size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // vector<vector<int>> zero(m+1,vector<int>(n+1,0));
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(matrix[i-1][j-1]==0)
        //         zero[i][j]=0;
        //         else{
        //             //zero[i][j]=min(1+zero[i-1][j],zero[i][j-1]);
        //             if(i==1){
        //                 zero[i][j]=1+zero[i][j-1];
        //             }
        //             else if(j==1){
        //                 zero[i][j]=1+zero[i-1][j];
        //             }
        //             else{
        //                 zero[i][j]=max(zero[i-1][j],zero[i][j-1]);
        //             }
        //         }
        //     }
        // }
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1] + min(zero[i][j],min(i,j));
        //     }
        // }
        // return dp[m][n];
    }
};