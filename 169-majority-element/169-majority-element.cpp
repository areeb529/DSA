class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        int ans=nums[0];
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])cnt++;
            else cnt=1;
            if(cnt>n/2){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};