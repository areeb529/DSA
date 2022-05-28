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
        vector<vector<int>> graph(n);
        for(auto &i:roads){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n,false);
        long long ans=0;
        for(int i=0;i<n;i++){
            for(auto &j:graph[i]){
                ans+=(mp[i]+mp[j]);
            }
        }
        return ans/2;
        
    }
};