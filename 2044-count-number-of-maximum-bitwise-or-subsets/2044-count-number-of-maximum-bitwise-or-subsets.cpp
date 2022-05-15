class Solution {
public:
    int res=0;
    void helper(vector<int>& nums,int i,int n,int maxOR,int bitOR){
        if(i==n){
            if(bitOR==maxOR)res++;
            return;
        }
        helper(nums,i+1,n,maxOR,bitOR);
        helper(nums,i+1,n,maxOR,bitOR|nums[i]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxOR=0;
        for(int i=0;i<n;i++){
            maxOR|=nums[i];
        }
        int bitOR=0;
        helper(nums,0,n,maxOR,bitOR);
        return res;
    }
};