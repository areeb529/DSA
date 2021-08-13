class Solution {
public:
    int rob(vector<int>&nums,int s,vector<int>&dp){
        if(s>=nums.size()){
            return 0;
        }
        if(dp[s]!=-1)return dp[s];
        int first_house=nums[s]+rob(nums,s+2,dp);
        int second_house=rob(nums,s+1,dp);
        dp[s]=max(first_house,second_house);
        return max(first_house,second_house);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return rob(nums,0,dp);
    }
};