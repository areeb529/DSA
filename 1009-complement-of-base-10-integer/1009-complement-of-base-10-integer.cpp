class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int mask=0;
        int i=0;
        while((1<<i)<=n){
            i++;
        }
        
        mask=(1<<i)-1;
        return n^mask;
    }
};