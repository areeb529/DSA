class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,int i,int n,vector<int> &sub){
        res.push_back(sub);
        for(int j=i;j<n;j++){
            sub.push_back(nums[j]);
            helper(nums,j+1,n,sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> sub;
        helper(nums,0,n,sub);
        return res;
    }
};