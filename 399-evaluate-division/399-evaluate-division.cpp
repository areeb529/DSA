class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> graph;
    unordered_map<string,bool> visited;
    double dfs(string &sv,string &ev){
        if(sv==ev)return 1.00000;
        visited[sv]=true;
        if(graph.count(sv)==0)return -1.00000;
        for(auto &i:graph[sv]){
            if(visited.count(i.first)==0){
                double ans=i.second*dfs(i.first,ev);
                if(ans>0.00000)return ans;
            }
        }
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        for(int i=0;i<n;i++){
            graph[equations[i][0]].push_back({equations[i][1],values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1.00000/values[i]});
        }
        int q=queries.size();
        vector<double> res(q,-1.00000);
        for(int i=0;i<q;i++){
            if(graph.count(queries[i][0])==0)continue;
            double ans=dfs(queries[i][0],queries[i][1]);
            if(ans>0)res[i]=ans;
            visited.clear();
        }
        return res;
    }
};