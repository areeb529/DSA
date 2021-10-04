class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m=g.size(),n=s.size();
        int k=0;
        int ct=0;
        for(int i=0;k<n&&i<m;i++){
            if(g[i]<=s[k]){
                ct++;
            }
            else{
                i--;
            }
            k++;
        }
        return ct;
    }
};