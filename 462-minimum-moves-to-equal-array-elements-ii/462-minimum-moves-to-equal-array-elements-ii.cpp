class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int equalElement;
        int mid=n/2;
        if(n&1){
            equalElement=nums[mid];
        }
        else{
            equalElement=(nums[mid-1]+nums[mid])/2;
        }
        int minOp=0;
        for(int i=0;i<n;i++){
            minOp+=(abs(nums[i]-equalElement));
        }
        return minOp;
    }
};