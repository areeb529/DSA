class Solution {
public:
    int findLUSlength(string a, string b) {
        int m=a.size(),n=b.size();
        if(a==b)return -1;
        else return max(m,n);
    }
};