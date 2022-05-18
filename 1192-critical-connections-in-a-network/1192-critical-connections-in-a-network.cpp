class Solution {
public:
    vector<vector<int>> res;
    int time=0;
    void dfs(vector<vector<int>> &graph,int sv,int p,vector<int> &disTime,vector<int> &lowTime){
        time++;
        disTime[sv]=time;
        lowTime[sv]=time;
        for(auto &i:graph[sv]){
            if(lowTime[i]==-1){
                dfs(graph,i,sv,disTime,lowTime);
                lowTime[sv]=min(lowTime[sv],lowTime[i]);
                if(lowTime[i]>disTime[sv])res.push_back({sv,i});
            }
            else if(i!=p){
                lowTime[sv]=min(lowTime[sv],lowTime[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto &i:connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int> disTime(n,-1);
        vector<int> lowTime(n,-1);
        dfs(graph,0,-1,disTime,lowTime);
        return res;
    }
};