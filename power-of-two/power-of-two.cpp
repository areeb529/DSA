class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        int x=1;
        while(x<=n){
            if(x==n)return true;
            if(x>INT_MAX/2)return false;
            x=x<<1;
        }
        return false;
    }
};