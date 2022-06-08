class Solution {
public:

    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<int> nums(n+1,0);
        int cnt=0;
        for(int i=2;i*i<=n;i++){
            if(!nums[i]){
                for(int j=i*i;j<=n;j+=i){
                    if(!nums[j]){
                        nums[j]=1;
                        cnt++;
                    }
                }
            }
        }
        int ans=0;
        if(nums[n]){
            ans=n-1-cnt;
        }
        else{
            ans=n-1-cnt-1;
        }
        return ans;
       
    }
};