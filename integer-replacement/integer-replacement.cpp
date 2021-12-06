class Solution {
public:
    
    int integerReplacement(int n) {
        if(n==1)return 0;
        if(n&1){
            int op1=1+integerReplacement(n-1);
            int op2=INT_MAX;
            if(n!=INT_MAX)
            op2=1+integerReplacement(n+1);
            else op2=2+integerReplacement(n/2+1);
            return min(op1,op2);
        }
        return 1+integerReplacement(n/2);
    }
};