class Solution {
public:
    int helper(unsigned int dividend, unsigned int divisor){
        if(dividend<divisor)return 0;
        if(divisor==1)return dividend;
        int temp=divisor;
        int ct=1;
        while(temp<=dividend){
            if(temp>(dividend>>1)||temp>(INT_MAX>>1))break;
            temp=temp<<1;
            if(ct>(INT_MAX>>1))break;
            ct=ct<<1;
        }
        int ans = ct+helper(dividend-temp,divisor);
        return ans;
    }
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        if(divisor==1)return dividend;
        unsigned int ans=0;
        int a=abs(dividend);
        unsigned int b=abs(divisor);
        if(dividend==INT_MIN&&divisor==-1)return INT_MAX;
        ans=helper(a,b);
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))return -ans;
        return ans; 
        
    }
};