class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0||k==1)return 0;
        int i=0,j=0;
        int curr=1;
        int cnt=0;
        while(j<n){
            curr=curr*nums[j];
            while(i<=j&&curr>=k){
                curr=curr/nums[i];
                i++;
            }
            if(curr<k){
                cnt=cnt+j-i+1;
            }
            j++;
        }
        return cnt;
    }
};