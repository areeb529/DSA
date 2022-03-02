class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size(),n=t.size();
        int j=0;
        for(int i=0;i<m;i++){
            bool f=false;
            for(;j<n;j++){
               if(s[i]==t[j]){
                   f=true;
                   j++;
                   break;
               }
            }
            if(!f)return false;
        }
        return true;
    }
};