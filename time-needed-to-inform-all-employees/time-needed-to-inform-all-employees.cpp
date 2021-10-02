class Solution {
public:
    int dfs(vector<vector<int>> &graph,int n,vector<int>& manager, vector<int>& informTime,int headID){
        int maxT=0;
        for(int i=0;i<graph[headID].size();i++){
            maxT=max(maxT,dfs(graph,n,manager,informTime,graph[headID][i]));
        }
        return informTime[headID]+maxT;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(manager[i]==-1)continue;
            graph[manager[i]].push_back(i);
        }
        return dfs(graph,n,manager,informTime,headID);
    }
};