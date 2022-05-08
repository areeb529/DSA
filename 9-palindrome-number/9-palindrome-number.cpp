class Solution {
public:
    bool isPalindrome(int x) {
        int num=0;
        int org=x;
        while(org){
            if(num>INT_MAX/10)return false;
            if(x>=0&&num==INT_MAX/10){
                if(org%10>(INT_MAX%10))return false;
            }
            if(x<0&&num==INT_MAX/10){
                if(org%10>(INT_MAX%10+1))return false;
            }
            if(org==INT_MIN){
                num=INT_MAX%10+1;
            }
            else{
               num=num*10+org%10; 
            }
            org/=10;
        }
        return num==abs(x);
    }
};