class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i])==0)st.insert(nums[i]);
            else return true;
        }
        return false;
        
    }
};