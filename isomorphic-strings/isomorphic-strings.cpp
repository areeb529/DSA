class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
            if(mp1.count(s[i])==0){
                if(mp2.count(t[i])!=0)return false;
                mp1[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }
            else{
                if(mp1[s[i]]!=t[i])return false;
            }
        }
        return true;
    }
};