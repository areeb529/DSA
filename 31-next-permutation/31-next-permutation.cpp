class Solution {
public:
    int upperBound(vector<int>& nums,int i,int j,int key){
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]>key){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool f=false;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                f=true;
                int idx=upperBound(nums,i,n-1,nums[i-1]);
                swap(nums[i-1],nums[idx]);
                sort(nums.begin()+i,nums.end());
                break;
            }
        }
        if(!f)reverse(nums.begin(),nums.end());
    }
};