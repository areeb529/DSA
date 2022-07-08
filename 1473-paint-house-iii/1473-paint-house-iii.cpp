class Solution {
public:
    int MAX=1e7+1;
    int helper(vector<int>& houses, int i,int prev,vector<vector<int>>& cost, int m, int n, int target,vector<vector<vector<int>>> &dp){
        if(target<0)return MAX;
        if(i==m){
            if(target==0)return 0;
            else return MAX;
        }
       // cout<<i<<" "<<prev<<" "<<target<<endl;
        if(dp[i][prev][target]!=-1)return dp[i][prev][target];
        if(houses[i]!=0){
            if(houses[i]!=prev)return dp[i][prev][target]=helper(houses,i+1,houses[i],cost,m,n,target-1,dp);
            else return dp[i][prev][target]=helper(houses,i+1,houses[i],cost,m,n,target,dp);
        }
        int ans=MAX;
        for(int j=1;j<=n;j++){
            if(j!=prev){
                int temp=helper(houses,i+1,j,cost,m,n,target-1,dp);
                ans=min(ans,cost[i][j-1]+temp);
            }
            else{
                int temp=helper(houses,i+1,j,cost,m,n,target,dp);
                ans=min(ans,cost[i][j-1]+temp);
            } 
        }
        return dp[i][prev][target]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        int ans=helper(houses,0,0,cost,m,n,target,dp);
        if(ans==MAX)ans=-1;
        return ans;
    }
};