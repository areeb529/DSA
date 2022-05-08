class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)return true;
        if(x<0||x%10==0)return false;
        int sum1=abs(x);
        int sum2=0;
        while(sum1>sum2){
            sum2=sum2*10+sum1%10;
            sum1/=10;
        }
        return sum1==sum2||sum2/10==sum1;
    }
};