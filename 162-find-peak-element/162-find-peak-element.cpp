class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if((mid-1<0||nums[mid-1]<nums[mid])&&(mid+1==n||nums[mid]>nums[mid+1])){
                ans = mid;
                break;
            }
            else if(mid>0&&nums[mid-1]>nums[mid])high=mid-1;
            else low=mid+1;
        }
        return ans;
               
    }
};