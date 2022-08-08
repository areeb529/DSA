class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mp;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(mp.count(temp)==0){
                vector<string> v;
                v.push_back(strs[i]);
                res.push_back(v);
                mp[temp]=res.size()-1;
            }
            else{
                res[mp[temp]].push_back(strs[i]);
            }
        }
        return res;
    }
};