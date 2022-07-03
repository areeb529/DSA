class Solution {
public:
    // int helper(vector<int>& nums,int i,int prevI,int n,int prevSign,vector<vector<vector<int>>> &dp){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i][prevI][prevSign]!=-1)return dp[i][prevI][prevSign];
    //     int sign=-1;
    //     if(nums[i]-nums[prevI]>0)sign=1;
    //     if(nums[i]-nums[prevI]<0)sign=0;
    //     if(sign==-1||sign==prevSign)return helper(nums,i+1,prevI,n,prevSign,dp);
    //     return dp[i][prevI][prevSign]=max(1+helper(nums,i+1,i,n,sign,dp),helper(nums,i+1,prevI,n,prevSign,dp));
    // }
    int helper(vector<int> &nums,int n,int prevSign){
        int prevI=0;
        int length=0;
        for(int i=1;i<n;i++){
            int sign=-1;
            if(nums[i]-nums[prevI]>0)sign=1;
            if(nums[i]-nums[prevI]<0)sign=0;
            if(sign==-1||sign==prevSign)continue;
            if(prevSign){
                while(i+1<n&&nums[i]>nums[i+1])i++;
            }
            else{
                while(i+1<n&&nums[i]<nums[i+1])i++;
            }
            prevI=i;
            prevSign=sign;
            length++;
        }
        return length;
    }
    int wiggleMaxLength(vector<int>& nums) {
        // int n=nums.size();
        // if(n==1)return n;
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        // return 1+max(helper(nums,1,0,n,0,dp),helper(nums,1,0,n,1,dp));
        int n=nums.size();
        return 1+max(helper(nums,n,0),helper(nums,n,1));
    }
};