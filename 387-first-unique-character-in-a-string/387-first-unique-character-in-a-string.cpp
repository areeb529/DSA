class Solution {
public:
    unordered_map<char,int> mp;
    int firstUniqChar(string s) {
        for(auto &i:s){
            mp[i]++;
        }
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1)return i;
        }
        return -1;
    }
};