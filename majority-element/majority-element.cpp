class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ct=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0){
                ct++;
                if(ct==n/2+1)return nums[i];
                continue;
            }
            if(nums[i]==nums[i-1])ct++;
            else
                ct=1;
            if(ct==n/2+1)return nums[i];
            
        }
        return nums[0];
    }
};