class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>res[res.size()-1]){
                res.push_back(nums[i]);
            }
            else{
                auto lb=lower_bound(res.begin(),res.end(),nums[i]);
                *lb=nums[i];
            }
        }
        return res.size();
    }
};