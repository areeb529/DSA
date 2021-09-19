class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int sv,vector<bool>&visited){
        visited[sv]=true;
        for(auto &i: rooms[sv]){
            if(!visited[i])
            dfs(rooms,i,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        dfs(rooms,0,visited);
        for(auto i:visited){
            if(!i)return false;
        }
        return true;
    }
};