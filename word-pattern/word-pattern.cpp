class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mp;
        unordered_map<char,string> cp;
        int n=s.size();
        int m=pattern.size();
        vector<string> v;
        stringstream ssr(s);
        string word;
        while(ssr>>word){
            v.push_back(word);
        }
        if(v.size()!=m)return false;
        for(int i=0;i<m;i++){
            if(cp.count(pattern[i])==0){
                if(mp.count(v[i])==1)return false;
                else{
                    cp[pattern[i]]=v[i];
                    mp[v[i]]=pattern[i];
                }
            }
            else{
                if(cp[pattern[i]]!=v[i])return false;
            }
        }
        return true;
    }
};