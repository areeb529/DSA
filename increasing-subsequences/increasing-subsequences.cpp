class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int i,vector<int> &subq,int n){
        if(subq.size()>=2)
        ans.push_back(subq);
        unordered_set<int> st;
        for(int j=i;j<n;j++){
            if(st.count(nums[j])==0){
                if(subq.empty()||subq[subq.size()-1]<=nums[j]){
                    subq.push_back(nums[j]);
                    helper(nums,j+1,subq,n);
                    subq.pop_back();
                    st.insert(nums[j]);
                }    
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int> subq;
        helper(nums,0,subq,n);
        return ans;
    }
};