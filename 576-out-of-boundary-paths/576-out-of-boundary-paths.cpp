class Solution {
public:
    int mod=1e9+7;
    int memo[51][51][51];
    int helper(int m,int n,int maxMove,int startRow,int startColumn){
        if(startRow<0||startRow>=m||startColumn<0||startColumn>=n){
            return 1;
        }
        if(maxMove<=0)return 0;
        if(memo[maxMove][startRow][startColumn]!=-1)return memo[maxMove][startRow][startColumn];
        int res=0;
        res=(res+helper(m,n,maxMove-1,startRow+1,startColumn))%mod;
        res=(res+helper(m,n,maxMove-1,startRow,startColumn+1))%mod;
        res=(res+helper(m,n,maxMove-1,startRow-1,startColumn))%mod;
        res=(res+helper(m,n,maxMove-1,startRow,startColumn-1))%mod;

        return memo[maxMove][startRow][startColumn]=res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo,-1,sizeof(memo));
        return helper(m,n,maxMove,startRow,startColumn);
    }
};