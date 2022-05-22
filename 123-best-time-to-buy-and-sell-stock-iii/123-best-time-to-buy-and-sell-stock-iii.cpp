class Solution {
public:
    
    // int maxProfit(vector<int>& prices,int i,int k,int n,vector<vector<int>> &dp){
    //     if(i==n||k==0){
    //         return 0;
    //     }
    //     if(dp[i][k]!=-1)return dp[i][k];
    //     int ans=0;
    //     int minM=prices[i];
    //     for(int j=i+1;j<n;j++){
    //         if(minM<prices[j]){
    //             ans=max(ans,prices[j]-minM+maxProfit(prices,j+1,k-1,n,dp));
    //         }
    //         else{
    //             minM=prices[j];
    //         }
    //     }
    //     return dp[i][k]=ans;
    // }
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // int k=2;
        // vector<vector<int>> dp(n,vector<int>(k+1,-1));
        // return maxProfit(prices,0,k,n,dp);
        int n=prices.size();
        vector<int> dp(n);
        int minPrice=prices[0];
        int maxProfit=0;
        for(int i=0;i<n;i++){
            minPrice=min(minPrice,prices[i]);
            int currProfit=prices[i]-minPrice;
            if(currProfit>maxProfit){
                maxProfit=currProfit;
            }
            dp[i]=maxProfit;
        }
        int maxPrice=prices[n-1];
        int ans=0;
        maxProfit=0;
        for(int i=n-1;i>=0;i--){
            maxPrice=max(maxPrice,prices[i]);
            int currProfit=maxPrice-prices[i];
            if(currProfit>maxProfit){
                maxProfit=currProfit;
            }
            ans=max(ans,maxProfit+dp[i]);
        }
        return ans;
        
    }
};