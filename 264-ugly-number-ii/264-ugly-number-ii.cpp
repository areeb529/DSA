class Solution {
public:

    int nthUglyNumber(int n) {
        vector<int> dp(n,1);
        dp[0]=1;
        int p1=0,p2=0,p3=0;
        for(int i=1;i<n;i++){
            int f1=2*dp[p1],f2=3*dp[p2],f3=5*dp[p3];
            int minM=min(f1,min(f2,f3));
            dp[i]=minM;
            if(minM==f1)p1++;
            if(minM==f2)p2++;
            if(minM==f3)p3++;
        }
        return dp[n-1];
        
    }
};