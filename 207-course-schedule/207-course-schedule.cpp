class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int sv,vector<int> &visited){
        if(visited[sv]<0)return false;
        visited[sv]=-1;
        for(auto &i:graph[sv]){
            if(visited[i]>0)continue;
            if(!dfs(graph,i,visited))return false;
        }
        visited[sv]=1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &i:prerequisites){
            graph[i[0]].push_back(i[1]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool ans=dfs(graph,i,visited);
                if(!ans)return false;
            }
        }
        return true;
        
    }
};