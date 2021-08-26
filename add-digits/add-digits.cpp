class Solution {
public:
    long long sum(int n){
        long long ans=0;
        while(n>0){
            ans+=n%10;
            n=n/10;
        }
        return ans;
    }
    int addDigits(int num) {
        long long n=num;
        while(n>9){
            n=sum(n);
        }
        return n;
    }
};