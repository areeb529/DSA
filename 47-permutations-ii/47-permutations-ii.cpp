class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,int i,int n){
        if(i==n){
            res.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]||st.count(nums[j])==1)continue;
            st.insert(nums[j]);
            swap(nums[i],nums[j]);
            helper(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
        st.clear();
        helper(nums,i+1,n);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        helper(nums,0,n);
        return res;
    }
};