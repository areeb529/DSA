class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int sv,vector<int> &visited,vector<int> &ans){
        bool f=true;
        visited[sv]=0;
        for(auto i:graph[sv]){
            if(visited[i]==-1){
                f=dfs(graph,i,visited,ans);
            }
            else{
                if(visited[i]!=1)f=false;
            }
            if(!f){
                visited[sv]=2;
                return false;
            }
        }
        visited[sv]=1;
        ans.push_back(sv);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(visited[i]==-1)
            dfs(graph,i,visited,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};