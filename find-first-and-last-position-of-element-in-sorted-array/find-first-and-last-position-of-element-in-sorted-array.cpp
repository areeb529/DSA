class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int i=0,j=nums.size()-1,t1=-1,t2=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                t1=mid;
                j=mid-1;
            }
            else if(nums[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        v.push_back(t1);
        i=0,j=nums.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                t2=mid;
                i=mid+1;
            }
            else if(nums[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        v.push_back(t2);
        return v;
    }
};