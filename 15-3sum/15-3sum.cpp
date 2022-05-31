class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j+1<n&&nums[j]==nums[j+1])j++;
                    j++;
                    while(j<k-1&&nums[k-1]==nums[k])k--;
                    k--;
                }
                else if(sum<0){
                    while(j+1<n&&nums[j]==nums[j+1])j++;
                    j++;
                }
                else{
                    while(j<k-1&&nums[k-1]==nums[k])k--;
                    k--;
                }
            }
            while(i+1<n&&nums[i]==nums[i+1])i++;
        }
        return res;
    }
};