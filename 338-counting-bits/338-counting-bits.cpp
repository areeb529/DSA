class Solution {
public:
    // int getSetBits(int num){
    //     int cnt=0;
    //     while(num){
    //         if(num&1)cnt++;
    //         num=num>>1;
    //     }
    //     return cnt;
    // }
    vector<int> countBits(int n) {
        // vector<int> dp(n+1);
        // for(int i=0;i<=n;i++){
        //     dp[i]=getSetBits(i);
        // }
        // return dp;
        vector<int> dp(n+1,1);
        dp[0]=0;
        if(n<=2)return dp;
        for(int i=3;i<=n;i++){
            if(i&1){
                dp[i]=dp[i>>1]+1;
            }
            else{
                dp[i]=dp[i>>1];
            }
        }
        return dp;
    }
};