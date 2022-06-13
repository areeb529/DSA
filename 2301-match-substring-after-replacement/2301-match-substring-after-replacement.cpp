class Solution {
public:
    unordered_map<char,unordered_set<char>> mp;
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n=s.size();
        int m=sub.size();
        for(auto &i:mappings){
            mp[i[0]].insert(i[1]);
        }
        for(int i=0;i<=n-m;i++){
            bool flag=true;
            for(int j=0;j<m;j++){
                if(s[i+j]==sub[j]||mp.count(sub[j])==1&&mp[sub[j]].count(s[i+j])==1)continue;
                else{
                    flag=false;
                    break;
                }
            }
            if(flag)return true;
        }
        return false;
        
    }
};