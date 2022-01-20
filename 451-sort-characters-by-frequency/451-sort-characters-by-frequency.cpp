class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        vector<vector<char>> bucket(n+1);
        for(auto &i:mp){
            bucket[i.second].push_back(i.first);
        }
        string res;
        for(int i=n;i>=0;i--){
            for(auto c:bucket[i]){
                int freq=0;
                while(freq<i){
                    res.push_back(c);
                    freq++;
                }
            }
        }
        return res;
    }
};