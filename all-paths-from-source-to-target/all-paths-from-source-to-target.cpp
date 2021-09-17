class Solution {
public:
    void dfs(vector<vector<int>>& graph,int sv,int e,vector<vector<int>> &ans,vector<int>&v,vector<bool>&visited){
        if(sv==e){
            v.push_back(sv);
            ans.push_back(v);
            return;
        }
        visited[sv]=true;
        v.push_back(sv);
        for(auto &i:graph[sv]){
            if(!visited[i])dfs(graph,i,e,ans,v,visited);
            v.pop_back();
        }
        visited[sv]=false;  
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n=graph.size();
        vector<int> v;
        vector<bool> visited(n,false);
        dfs(graph,0,n-1,ans,v,visited);
        return ans;
    }
};