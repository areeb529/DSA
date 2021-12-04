class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxM=INT_MIN;
        int minM=INT_MAX;
        int maxI=0;
        int minI=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxM){
                maxM=nums[i];
                maxI=i;
            }
            if(nums[i]<minM){
                minM=nums[i];
                minI=i;
            }
        }
        int op1=min(minI,maxI)+1;
        int op2=n-max(maxI,minI);
        int op3=abs(maxI-minI);
        return min(op1+op2,min(op1+op3,op2+op3));
    }
};