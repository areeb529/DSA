class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minmax=INT_MIN;
        int n=nums.size();
        for(int i=0,j=n-1;i<j;i++,j--){
            minmax=max(minmax,nums[i]+nums[j]);
        }
        return minmax;
    }
};