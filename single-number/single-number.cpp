class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int uni=nums[0];
        for(int i=1;i<nums.size();i++){
            uni=uni^nums[i];
        }
        return uni;
    }
};