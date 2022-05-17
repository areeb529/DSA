class Solution {
public:
    void dfs(vector<vector<int>> &graph,int sv,vector<bool> &visited){
        visited[sv]=true;
        for(auto &i:graph[sv]){
            if(!visited[i])dfs(graph,i,visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numEdges=connections.size();
        vector<vector<int>> graph(n);
        for(auto &i:connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n,false);
        int numConnectedComponents=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                numConnectedComponents++;
                dfs(graph,i,visited);
            }
        }
        if(numEdges<n-1)return -1;
        else return numConnectedComponents-1;
    }
};