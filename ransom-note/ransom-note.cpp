class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto i:ransomNote){
            mp[i]++;
        }
        for(auto i:magazine){
            if(mp.count(i)==1){
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
        }
        if(mp.size()==0)return true;
        else return false;
    }
};