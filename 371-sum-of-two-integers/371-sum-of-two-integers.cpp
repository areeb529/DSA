class Solution {
public:
    int getSum(int a, int b) {
        // int carry=0;
        // int sum=0;
        // int i=0;
        // while(a||b||carry){
        //     int x=a&1;
        //     int y=b&1;
        //     int Xor=x^y^carry;
        //     sum=sum|(Xor<<i);
        //     if((Xor==0&&(x|y|carry))||(Xor==1&&(x&y&carry)==1))carry=1;
        //     else carry=0;
        //     a=a>>1;
        //     b=b>>1;
        //     i++;
        // }
        // return sum;
        while(a){
            int carry=(a&b);
            int add=a^b;
            carry=(unsigned int)carry<<1;
            a=carry;
            b=add;
        }
        return b;
    }
};