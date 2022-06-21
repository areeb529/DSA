class Solution {
public:
    // int helper(string &s,int i,int n,int k,long long sum,int p){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(s[i]=='0'){
    //         if(p<=k)
    //         return 1+helper(s,i+1,n,k,sum,p*2);
    //         else{
    //             p=0;
    //             return 1+helper(s,i+1,n,k,sum,p);
    //         }
    //     }
    //     else{
    //         if(sum+(s[i]-'0')*p<=k&&p){
    //             return 1+helper(s,i+1,n,k,sum+(s[i]-'0')*p,p*2);
    //         }
    //         else{
    //             p=0;
    //             return helper(s,i+1,n,k,sum,p);
    //         }
    //     }
    // }
    int longestSubsequence(string s, int k) {
        int n=s.size();
        int cnt=0,pow=1,sum=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                if(pow<=k)
                pow*=2;
                cnt++;
            }
            else{
                if(sum+(s[i]-'0')*pow<=k){
                    sum=sum+(s[i]-'0')*pow;
                    pow*=2;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};