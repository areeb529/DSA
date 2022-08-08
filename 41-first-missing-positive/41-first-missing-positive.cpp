class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==i+1||nums[i]>n||nums[i]<=0)i++;
            else{
                if(nums[nums[i]-1]==nums[i])i++;
                else swap(nums[i],nums[nums[i]-1]);
            }
        }
        int ans=n+1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};