class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        if(s==t)return 1;
        else return 2;
        
    }
};