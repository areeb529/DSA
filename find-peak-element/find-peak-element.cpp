class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if((mid==0||nums[mid]>nums[mid-1])&&(mid==n-1||nums[mid]>nums[mid+1])){
                ans=mid;
                return mid;
            }
            else if(nums[mid]<=nums[mid+1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};