class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<=((1<<n)-1);i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                int mask=1<<j;
                if(mask&i){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};