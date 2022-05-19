class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> minArray(n,INT_MAX);
        vector<int> maxArray(n,-1);
        int minM=INT_MAX,maxM=INT_MIN;
        for(int i=0;i<n;i++){
            minM=minArray[n-1-i]=min(minM,nums[n-1-i]);
            maxM=maxArray[i]=max(maxM,nums[i]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(maxArray[i]<=minArray[i+1]){
                ans=i+1;
                break;
            }
        }
        return ans;
        
    }
};