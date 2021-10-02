class Solution {
public:
    int helper(vector<vector<int>>& dungeon,int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==m-1&&j==n-1){
            return dungeon[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int a=INT_MIN,b=INT_MIN;
        if(j+1<n){
            a=helper(dungeon,m,n,i,j+1,dp);
        }
        if(i+1<m){
            b=helper(dungeon,m,n,i+1,j,dp);
        }
        int x=max(a,b);
        if(x==INT_MIN) x=0;
        if(dungeon[i][j]>=0){
            return dp[i][j]=dungeon[i][j]+x;
        }
        else{
            return dp[i][j]=min(dungeon[i][j],dungeon[i][j]+x);
        }
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=helper(dungeon,m,n,0,0,dp);
        if(ans>0)return 1;
        else return abs(ans)+1;
    }
};