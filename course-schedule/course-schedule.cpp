class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int n,int sv,vector<bool> &visited,vector<bool> &vis){
        if(vis[sv])return true;
        if(visited[sv])return false;
        visited[sv]=true; 
        vis[sv]=true;
        for(auto &i:graph[sv]){
            bool f=dfs(graph,n,i,visited,vis);
            if(f)return true;
        }
        vis[sv]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &i:prerequisites){
            graph[i[0]].push_back(i[1]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> vis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool ans=dfs(graph,numCourses,i,visited,vis); 
                if(ans)return false;
            }
        }
        return true;
    }
};