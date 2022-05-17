class Solution {
public:
    int numCycles=0;
    int numConnectedComponents=0;
    void dfs(vector<vector<int>> &graph,int sv,int p,vector<bool> &visited){
        visited[sv]=true;
        for(auto &i:graph[sv]){
            if(!visited[i])dfs(graph,i,sv,visited);
            else if(i!=p)numCycles++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto &i:connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                numConnectedComponents++;
                dfs(graph,i,-1,visited);
            }
        }
        if(numConnectedComponents==1)return 0;
        if(numCycles/2>=numConnectedComponents-1)return numConnectedComponents-1;
        else return -1;
    }
};