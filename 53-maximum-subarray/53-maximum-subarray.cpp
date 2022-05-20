class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=nums[0];
        for(int i=0;i<n;i++){
            if(sum+nums[i]>=0){
                sum+=nums[i];
                ans=max(sum,ans);
            }
            else{
                sum=0;
                ans=max(ans,sum+nums[i]);
            }
        }
        return ans;
    }
};