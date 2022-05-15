class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int sv,int p,int color,vector<int>& visited){
        visited[sv]=color;
        for(auto &i:graph[sv]){
            if(visited[i]<0){
                bool ans=dfs(graph,i,sv,color^1,visited);
                if(!ans)return false;
            }
            else if(p!=i){
                if(visited[i]==color)return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]<0){
                bool ans=dfs(graph,i,-1,1,visited);
                if(!ans)return false;
            }
        }
        return true;
        
    }
};