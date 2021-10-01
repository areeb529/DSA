class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>&nums,int i,vector<int>&v,int n,int k){
        if(n==0&&v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<9;j++){
            if(nums[j]>n)break;
            v.push_back(nums[j]);
            helper(nums,j+1,v,n-nums[j],k);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9,0);
        for(int i=0;i<9;i++){
            nums[i]=i+1;
        }
        vector<int> v;
        helper(nums,0,v,n,k);
        return ans;
    }
};