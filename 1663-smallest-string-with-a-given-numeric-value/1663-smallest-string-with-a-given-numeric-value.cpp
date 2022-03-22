class Solution {
public:
    string getSmallestString(int n, int k) {
        int nV=n;
        string s(n,'a');
        int diff=k-nV;
        for(int i=n-1;i>=0&&diff;i--){
            int temp=s[i]-'a'+1+diff;
            if(temp<=26){
                s[i]=s[i]+diff;
                break;
            }
            else{
                diff=diff-('z'-s[i]);
                s[i]='z';
            }
        }
        return s;
    }
};