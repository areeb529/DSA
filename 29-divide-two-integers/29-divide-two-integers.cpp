class Solution {
public:
    int helper(int dividend, int divisor){
        if(dividend<divisor)return 0;
        if(divisor==1)return dividend;
        int temp=divisor;
        int ct=1;
        while(temp<=dividend){
            if((temp<<1)>dividend)break;
            if(temp<=(INT_MAX>>1))
            temp=temp<<1;
            else
                break;
            if(ct<=(INT_MAX>>1))
            ct=ct<<1;
            else break;
        }
        int ans = ct+helper(dividend-temp,divisor);
        return ans;
    }
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        int ans=0;
        if(dividend==INT_MIN){
            if(divisor==INT_MIN)return 1;
            else if(divisor==INT_MAX)return -1;
            else if(divisor==1)return INT_MIN;
            else if(divisor==-1)return INT_MAX;
            else{
                ans=helper(INT_MAX,abs(divisor));
                int x=abs(divisor);
                if((x&x-1)==0)ans++;
                if(divisor>0)ans=-ans;
                if(ans==-INT_MAX)ans=INT_MIN;
                return ans;
            }
        }
        else if(divisor==INT_MIN){
            if(dividend==INT_MIN)return 1;
            else if(dividend==INT_MAX)return 0;
            else{
                ans=helper(abs(dividend),INT_MAX);
                if(dividend>0)ans=-ans;
                return ans;
            }
        }
        
        ans=helper(abs(dividend),abs(divisor));
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))return -ans;
        return ans;
        
        //if divisor OR dividend == INT_MIN 
        
    }
};