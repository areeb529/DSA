class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ct=0;
        unordered_map<string,int> mp;
        mp["type"]=0;
        mp["color"]=1;
        mp["name"]=2;
        int idx=mp[ruleKey];
        for(auto &i:items){
            if(i[idx]==ruleValue)ct++;
        }
        return ct;
    }
};