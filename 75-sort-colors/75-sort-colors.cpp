class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(i+1<n&&nums[i]>nums[i+1]){
                swap(nums[i],nums[i+1]);
                while(i>0&&nums[i-1]>nums[i]){
                swap(nums[i-1],nums[i]);
                i--;
                }
            }
            i++;
        }
        
    }
};