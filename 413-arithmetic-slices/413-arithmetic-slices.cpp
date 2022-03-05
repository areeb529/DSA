class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int diff=nums[1]-nums[0];
        int ct=2;
        int res=0;
        for(int i=1;i<n-1;i++){
            if(nums[i+1]-nums[i]==diff){
                ct++;
                if(ct>=3)res+=ct-3+1;
            }
            else{
                ct=2;
                diff=nums[i+1]-nums[i];
            }
        }
        return res;
    }
};