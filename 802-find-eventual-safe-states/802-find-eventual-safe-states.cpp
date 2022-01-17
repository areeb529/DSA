class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int sv,vector<int> &visited){
        visited[sv]=1;
        bool f=true;
        for(auto i:graph[sv]){
            if(!visited[i]){
                f=dfs(graph,i,visited);
            }
            else{
                if(visited[i]==1)f=false;
            }
            if(!f){
                visited[sv]=1;
                return false;
            }
        }
        visited[sv]=2;
        return true;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> ans;
        bool f=true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                f=dfs(graph,i,visited);
            }
            else{
                if(visited[i]==1){
                    f=false;
                }
                else{
                    f=true;
                }
            }
            if(f)ans.push_back(i);
        }
        return ans;
    }
};