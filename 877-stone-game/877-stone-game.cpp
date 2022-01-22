class Solution {
public:
    int stoneGame(vector<int>& piles,int i,int j,vector<vector<int>> &dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=max(piles[i]+stoneGame(piles,i+1,j,dp),piles[j]+stoneGame(piles,i,j-1,dp));
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int totalStones=0;
        for(int i=0;i<n;i++){
            totalStones+=piles[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int aliceStones=stoneGame(piles,0,n-1,dp);
        if(aliceStones>=(totalStones+1)/2)return true;
        else return false;
    }
};