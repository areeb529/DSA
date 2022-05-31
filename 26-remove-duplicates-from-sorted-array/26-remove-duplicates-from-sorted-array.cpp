class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(i<n){
            if(i>0&&nums[i-1]==nums[i])i++;
            else nums[j++]=nums[i++];
        }
        return j;
    }
};