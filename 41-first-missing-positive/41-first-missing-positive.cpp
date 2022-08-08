class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>n)nums[i]=-1*nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]<=0)continue;
            int idx=nums[i]%(n+1)-1;
            if(idx<0||idx>=n)continue;
            if(nums[idx]<=0)nums[idx]=n+1;
            else if(nums[idx]>0&&nums[idx]<=n)nums[idx]+=n+1;
        }
        int ans=n+1;
        for(int i=0;i<n;i++){
            if(nums[i]<n+1){
                ans=i+1;
                break;
            }
        }
        return ans;
        
    }
};