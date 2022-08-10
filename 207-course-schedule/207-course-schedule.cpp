class Solution {
public:
    bool hasCycle(vector<vector<int>> &graph,int sv,vector<int> &visited){
        visited[sv]=2;
        for(auto &i:graph[sv]){
            if(!visited[i]){
                if(hasCycle(graph,i,visited))return true;
            }
            else if(visited[i]==2)return true;
        }
        visited[sv]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &i:prerequisites){
            graph[i[0]].push_back(i[1]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool hasCycleInComponent=hasCycle(graph,i,visited);
                if(hasCycleInComponent)return false;
            }
        }
        return true;
    }
};