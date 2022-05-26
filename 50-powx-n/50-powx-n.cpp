class Solution {
public:
    double helper(double x, int n){
        if(n==0)return 1.0;
        double res=helper(x,n/2);
        if(n&1){
            return x*res*res;
        }
        else{
            return res*res;
        }
    }
    double myPow(double x, int n) {
        if(x==0||x==1)return x;
        double ans;
        if(n<0){
            double reciprocal=helper(x,abs(n));
            ans= 1.0/reciprocal;
        }
        else{
            ans=helper(x,n);
        }
        return ans;
    }
};