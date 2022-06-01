class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            res[i]=sum;
        }
        return res;
    }
};