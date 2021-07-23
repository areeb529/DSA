class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int**t=new int*[m+1];
        for(int i=0;i<=m;i++){
            t[i]=new int[n+1];
        }
        for(int j=0;j<=n;j++){
            t[0][j]=j;
        }
        for(int i=0;i<=m;i++){
            t[i][0]=i;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[m-i]==word2[n-j]){
                    t[i][j]=t[i-1][j-1];
                }
                else{
                    t[i][j]=1+min(t[i-1][j],min(t[i-1][j-1],t[i][j-1]));
                }
            }
        }
        return t[m][n];
    }
};