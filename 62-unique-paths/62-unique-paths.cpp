class Solution {
public:
    int combinatorial(long n,int r){
        if(r==0)return 1;
        return (n*combinatorial(n-1,r-1))/r;
    }
    int uniquePaths(int m, int n) {
//         vector<int> dp(n+1,0);
//         int X=0,Y=0;
//         for(int i=m-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//                 if(i==m-1&&j==n-1)X=1;
//                 else X=X+Y;
                
//             }
//         }
//         return Y;
        return combinatorial(m+n-2,m-1);
    }
};