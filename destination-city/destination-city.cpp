class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> mp;
        string ans;
        for(auto it: paths){
            mp.insert(it[0]);
        }
        for(auto it:paths){
            if(mp.count(it[1])==0){
                ans=it[1];
                break;
            }
        }
        return ans;
    }
};