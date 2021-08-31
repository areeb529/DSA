class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1000000);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0)continue;
            for(int j=1;i+j<n&&j<=nums[i];j++){
                dp[i]=min(dp[i],1+dp[i+j]);
            }
        }
        return dp[0];
    }
};