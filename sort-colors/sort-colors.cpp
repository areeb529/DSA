class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j){
            if(nums[i]==2){
                if(nums[j]<nums[i]){
                    swap(nums[i],nums[j]);
                    j--;
                }
                else{
                    j--;
                    continue;
                }
            }
            if(i!=0){
                if(nums[i-1]>nums[i]){
                    swap(nums[i-1],nums[i]);
                    i-=2;
                }
            }
            i++;
        }
    }
};