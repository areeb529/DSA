class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> v(2,0);
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i])){
                v[0]=mp[target-nums[i]];
                v[1]=i;
                return v;
            }
            mp[nums[i]]=i;
        }
        return v;
    }
};