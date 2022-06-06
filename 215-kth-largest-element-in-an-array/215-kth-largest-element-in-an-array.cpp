class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int ct=0;
            for(int i=low+1;i<=high;i++){
                if(nums[i]>=nums[low])ct++;
            }
            int pivotIndex=low+ct;
            int pivot=nums[low];
            if(pivotIndex==k-1)return pivot;
            else{
                swap(nums[low],nums[pivotIndex]);
                int i=low,j=high;
                while(i<pivotIndex&&j>pivotIndex){
                    if(nums[i]>=pivot)i++;
                    else if(pivot>nums[j])j--;
                    else{
                        swap(nums[i],nums[j]);
                        i++;
                        j--;
                    }
                }
                if(pivotIndex<k-1){
                    low=pivotIndex+1;
                }
                else{
                    high=pivotIndex-1;
                }
            }
            
        }
        return nums[0];
    }
};