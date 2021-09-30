class Solution {
public:
     vector<vector<int>> ans;
    void helper(vector<int>& nums,int i,int n){
        if(i==n-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int j=i;j<n;j++){
            if(st.count(nums[j])==0)st.insert(nums[j]);
            else continue;
            swap(nums[i],nums[j]);
            helper(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        helper(nums,0,n);
        return ans;
    }
};