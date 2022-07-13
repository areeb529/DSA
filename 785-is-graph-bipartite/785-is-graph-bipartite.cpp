class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph,int sv,int p,vector<int> &color){
        if(p==-1)color[sv]=0;
        else color[sv]=color[p]^1;
        for(auto &i:graph[sv]){
            if(color[i]==-1){
                bool ans=isBipartite(graph,i,sv,color);
                if(!ans)return false;
            }
            else if(color[i]==color[sv]&&i!=p)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        bool ans=true;;
        for(int i=0;i<n;i++){
            if(color[i]==-1)
            ans=isBipartite(graph,i,-1,color);
            if(!ans)return false;
        }
        return true;
    }
};