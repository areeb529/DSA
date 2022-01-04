class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        for(int i=0;1<<i<=n;i++){
            int v=n&1<<i;
            int mask=~(1<<i);
            int cleared_n=n&mask;
            if(v){
                n=cleared_n|0<<i;
            }
            else{
                n=cleared_n|1<<i;
            }
        }
        return n;
    }
};