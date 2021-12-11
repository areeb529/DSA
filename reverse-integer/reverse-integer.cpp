class Solution {
public:
    int reverse(int x) {
        int temp=abs(x);
        int ans=0;
        while(temp){
            ans+=temp%10;
            temp/=10;
            if(temp==0)break;
            if(x>0){
                if(ans>INT_MAX/10||(ans==INT_MAX/10&&temp%10>INT_MAX%10))return 0;
            }
            if(x<0){
                if(-1*ans<INT_MIN/10||(-1*ans==INT_MIN/10&&temp%10>8))return 0;
            }
            ans*=10;
        }
        if(x<0)return -1*ans;
        return ans;
    }
};