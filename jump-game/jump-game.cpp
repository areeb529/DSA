class Solution {
public:
    bool canJump(vector<int>& nums) {
        //   int n=nums.size();
        // vector<int> dp(n);
        // dp[n-1]=1;
        // for(int i=n-2;i>=0;i--){
        //     if(nums[i]==0){
        //         dp[i]=0;
        //         continue;
        //     }
        //     else if(nums[i]>=n-1-i){
        //         dp[i]=1;
        //         continue;
        //     }
        //     else{
        //         bool f=false;
        //         for(int j=1;j<=nums[i];j++){
        //             if(dp[i+j]){
        //                 dp[i]=1;
        //                 f=true;
        //                 break;
        //             }
        //         }
        //         if(!f)dp[i]=0;
        //     }
        // }
        // return dp[0];
        
        //  int n=nums.size();
        // int maxReach=0;
        // for(int i=0;i<n;i++){
        //     if(i>maxReach)return false;
        //     if(maxReach>=n-1)return true;
        //     maxReach=max(maxReach,nums[i]+i);
        // }
        // return true;
        
        int n=nums.size();
        int maxReach=0;
        int reach=0;
        bool ans;
        for(int i=0;i<n;i++){
            if(i>maxReach){
                ans=false;
                break;
            }
            if(maxReach>=n-1){
                ans=true;
                break;
            }
            reach=i+nums[i];
            maxReach=max(maxReach,reach);
        }
        return ans;
    }
};