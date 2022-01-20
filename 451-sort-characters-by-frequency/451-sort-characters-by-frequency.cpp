class Solution {
public:
    // unordered_map<char,int> freq;
    //  static bool compare(const char &x,const char &y){
    //     return freq[x]>freq[y];
    // }
    static bool compare(const pair<char,int> &a,const pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        // int n=s.size();
        // for(int i=0;i<n;i++){
        //     freq[s[i]]++;
        // }
        // sort(s.begin(),s.end(),compare);
        // return s;
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> v;
        for(auto &it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),compare);
        string ans;
        for(int i=0;i<v.size();i++){
            int k=0;
            while(k<v[i].second){
                ans.push_back(v[i].first);
                k++;
            }
        }
        return ans;
    }
};