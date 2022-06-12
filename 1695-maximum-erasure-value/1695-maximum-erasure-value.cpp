class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),sum=0,maxSum=0;
        int mp[10001]={0};
        while(j<n){
            while(mp[nums[j]]){
                sum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            mp[nums[j]]++;;
            sum+=nums[j];
            maxSum=max(maxSum,sum);
            j++;
        }
        return maxSum;
    }
};