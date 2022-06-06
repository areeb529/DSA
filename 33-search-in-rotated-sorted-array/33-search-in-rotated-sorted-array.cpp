class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=-1;
        int low=0,high=n-1;
        while(low<=high){
            int mid=((high-low)>>1)+low;
            if(nums[low]==target)return low;
            else if(nums[high]==target)return high;
            else if(nums[mid]==target)return mid;
            else if(nums[low]<nums[mid]){
                if(nums[low]<=target&&target<nums[mid])high=mid-1;
                else low=mid+1;
            }
            else{
                if(nums[mid]<target&&target<=nums[high])low=mid+1;
                else high=mid-1;
            }
        }
        return ans;
    }
};