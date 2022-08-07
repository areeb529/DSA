class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> res(2);
        for(int i=0;i<n;i++){
            if(mp.count(target-nums[i])==1){
                res[0]=mp[target-nums[i]];
                res[1]=i;
                break;
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return res;
    }
};