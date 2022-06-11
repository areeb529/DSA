class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        if(n==1)return nums[0]==x?1:-1;
        int i=0,j=0;
        int sum=0;
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if(sum<x)return -1;
        if(sum==x)return n;
        sum=0;
        while(i<n){
            sum+=nums[j];
            while(sum>=x&&i<n){
                if(sum==x){
                    if(i<=j&&(i==0||j==n-1))res=min(res,j-i+1);
                    else if(i>j)res=min(res,j+1+n-i);
                }
                sum=sum-nums[i];
                i++;
            }
            j=(j+1)%n;
        }
        if(res==INT_MAX)res=-1;
        return res;
    }
};