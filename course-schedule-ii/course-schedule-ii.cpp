class Solution {
public:
    vector<int> ans;
    bool isCycle(vector<int> adj[],int n,int sv,vector<int> &visited){
        if(visited[sv]==-1)return false;
        visited[sv]=-1;
        for(auto &i:adj[sv]){
            if(visited[i]==-2)continue;
            bool f=isCycle(adj,n,i,visited);
            if(!f)return false;
        }
        visited[sv]=-2;
        ans.push_back(sv);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto &i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool f=isCycle(adj,n,i,visited);
                if(!f){
                    ans={};
                    return ans;
                }
            }
        }
        return ans;
    }
};