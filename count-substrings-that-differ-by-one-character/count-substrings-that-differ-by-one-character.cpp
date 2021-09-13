class Solution {
public:
    int countSubstrings(string s, string t) {
        int m=s.size(),n=t.size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i]!=t[j]){
                    int p=i-1,q=j-1;
                    int ct1=1;
                    while(p>=0&&q>=0){
                        if(s[p]!=t[q])break;
                        ct1++;
                        p--,q--;
                    }
                    ans+=ct1;
                    p=i+1,q=j+1;
                    int ct2=0;
                    while(p<m&&q<n){
                        if(s[p]!=t[q])break;
                        ct2++;
                        p++,q++;
                    }
                    ans+=ct1*ct2;
                }
            }
        }
        return ans;
    }
};