class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1])return nums[0];
        int p=0,q=n-1;
        while(p<q){
            int mid=p+(q-p)/2;
            if(nums[mid]>nums[q])p=mid+1;
            else q=mid;
        }
        return nums[p];
    }
};