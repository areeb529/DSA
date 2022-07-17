class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int GCD=numsDivide[0];
        
        for(int i=1;i<numsDivide.size();i++){
            GCD=__gcd(numsDivide[i],GCD);
        }
        for(int i=0;i<n;i++){
            if(GCD%nums[i]==0)return i;
        }
        return -1;
    }
};