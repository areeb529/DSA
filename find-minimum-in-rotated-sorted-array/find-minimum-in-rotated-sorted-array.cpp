class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int s=0,e=nums.size()-1;
        int ans=nums[s];
        if(nums[s]<nums[e])return nums[0];
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                ans=nums[mid];
                e=mid-1;
            }
        }
        return ans;
    }
};