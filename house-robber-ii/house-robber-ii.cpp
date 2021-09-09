class Solution {
public:
    int helper(vector<int> &nums,int i,int n){
        if(i==n||n==0){
            return 0;
        }
        vector<int> dp(n+2);
        dp[n+1]=0;
        dp[n]=0;
        for(int j=n-1;j>=i;j--){
            dp[j]=max(nums[j]+dp[j+2],dp[j+1]);
        }
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int i=0;
        int opt2=helper(nums,i+1,n);
        nums.pop_back();
        int opt1=nums[i]+helper(nums,i+2,n-1);
        return max(opt1,opt2);
    }
};