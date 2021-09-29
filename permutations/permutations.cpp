class Solution {
public:
    // vector<vector<int>> ans;
    // void helper(vector<int>& nums,int i,int n){
    //     if(i==n)return;
    //     helper(nums,i+1,n);
    //     for(int j=i+1;j<n;j++){
    //         swap(nums[i],nums[j]);
    //         ans.push_back(nums);
    //         helper(nums,i+1,n);
    //         swap(nums[i],nums[j]);
    //     }
    // }
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int i,int n){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            helper(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // int n=nums.size();
        // ans.push_back(nums);
        // helper(nums,0,n);
        // return ans;
        int n=nums.size();
        helper(nums,0,n);
        return ans;
    }
};