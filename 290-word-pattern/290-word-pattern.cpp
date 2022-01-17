class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mp;
        unordered_map<char,string> cp;
        int n=s.size();
        int m=pattern.size();
        int k=0;
        string temp;
        for(int i=0;i<n;i++){
            if(s[i]!=' ')
            temp.push_back(s[i]);
            if(s[i]==' '||i==n-1){
                if(mp.count(temp)==0){
                    if(cp.count(pattern[k])==1)return false;
                    mp[temp]=pattern[k];
                    cp[pattern[k]]=temp;
                    temp="";
                }
                else{
                    if(pattern[k]!=mp[temp])return false;
                    temp="";
                }
                 k++;
            }
        }
        if(k==m)return true;
        else return false;
    }
};