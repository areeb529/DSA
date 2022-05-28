class Solution {
public:
    unordered_map<int,int> mp;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        for(auto &i:roads){
            degree[i[0]]++;
            degree[i[1]]++;
        }
        vector<pair<int,int>> dgi(n);
        for(int i=0;i<n;i++){
            dgi[i]={degree[i],i};
        }
        sort(dgi.begin(),dgi.end());
        for(int i=0;i<n;i++){
            mp[dgi[i].second]=i+1;
        }
       long long ans=0;
        for(auto &i:roads){
            ans+=(mp[i[0]]+mp[i[1]]);
        }
        return ans;
    }
};