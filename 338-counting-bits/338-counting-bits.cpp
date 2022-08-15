class Solution {
public:
    int getSetBits(int num){
        int cnt=0;
        while(num){
            if(num&1)cnt++;
            num=num>>1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i]=getSetBits(i);
        }
        return dp;
    }
};