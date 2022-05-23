class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,int i,int n,vector<int> &sub){
       if(i==n){
           res.push_back(sub);
           return;
       }
        sub.push_back(nums[i]);
        helper(nums,i+1,n,sub);
        sub.pop_back();
        int j=i;
        while(j+1<n&&nums[j]==nums[j+1]){
            j++;
        }
        helper(nums,j+1,n,sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> sub;
        helper(nums,0,n,sub);
        return res;
    }
};