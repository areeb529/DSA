class Solution {
public:
    int bs(vector<int>& nums,int s,int e,int key){
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>key){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool f=false;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                f=true;
                reverse(nums.begin()+i+1,nums.end());
                int idx=bs(nums,i+1,n-1,nums[i]);
                swap(nums[i],nums[idx]);
                break;
            }
        }
        if(!f){
            reverse(nums.begin(),nums.end());
        }
    }
};