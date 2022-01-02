class Solution {
public:
    int maxCoins(vector<int> &arr,int left,int right,vector<vector<int>> &dp){
        if(left+1==right)return 0;
        int ans=0;
        if(dp[left][right]!=-1)return dp[left][right];
        for(int k=left+1;k<right;k++){
            ans=max(ans,arr[left]*arr[k]*arr[right]+maxCoins(arr,left,k,dp)+maxCoins(arr,k,right,dp));
        }
        return dp[left][right]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+2,1);
        for(int i=1;i<=n;i++){
            arr[i]=nums[i-1];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        int left=0,right=n+1;
        return maxCoins(arr,left,right,dp);
    }
};