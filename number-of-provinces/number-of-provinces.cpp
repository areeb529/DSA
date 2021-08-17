class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool> &visited,int sv,int n){
        visited[sv]=true;
        for(int i=0;i<n;i++){
            if(!visited[i]&&isConnected[sv][i]){
                dfs(isConnected,visited,i,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ct=0;
        int n=isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
            ct++;
            dfs(isConnected,visited,i,n);
            }
        }
        return ct;
    }
};