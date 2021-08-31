class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        if(n==0||n==1)return n;
        int i=1;
        while(i<n){
            if(nums[i]!=nums[i-1]){
                nums[k]=nums[i-1];
                k++;
            }
            if(i==n-1){
                    nums[k]=nums[i];
                    k++;
            }
            i++;
        }
        return k;
        
    }
};