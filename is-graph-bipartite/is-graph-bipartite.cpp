class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph,int n,int sv,int p,vector<int> &visited){
         if(p!=-1)
        visited[sv]=visited[p]^1;
         else visited[sv]=0;
        bool ans=true;
        for(auto &i:graph[sv]){
            if(visited[i]==-1){
                ans=isBipartite(graph,n,i,sv,visited);
                if(!ans)return false;
            }
            else if(i!=p){
                if(visited[sv]==visited[i])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            bool ans=true;
            if(visited[i]==-1){
                ans=isBipartite(graph,n,i,-1,visited);
                if(!ans)return false;
            }
        }
        return true;
    }
};