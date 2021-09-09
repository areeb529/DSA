class Solution {
public:
    int helper(vector<int> &nums,int i,int n){
        if(i>n){
            return 0;
        }
        int b=0;
        int c=0;
        for(int j=n;j>=i;j--){
            int a=max(nums[j]+b,c);
            b=c;
            c=a;
        }
        return c;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int i=0;
        int opt1=helper(nums,i,n-2);
        int opt2=helper(nums,i+1,n-1);
        
        return max(opt1,opt2);
    }
};