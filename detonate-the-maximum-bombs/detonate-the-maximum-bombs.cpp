class Solution {
public:
   bool inRange(int x1,int y1,int x2,int y2,int r){
        return (long)(x2-x1)*(x2-x1)+(long)(y2-y1)*(y2-y1)<=(long)r*r;
    }
    void helper(vector<vector<int>>& bombs,int sv,int &k,vector<bool>&visited,int n){
        visited[sv]=true;
        k++;
                int x1=bombs[sv][0];
                int y1=bombs[sv][1];
                int r1=bombs[sv][2];
            for(int j=0;j<n;j++){
                if(visited[j])continue;
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                int r2=bombs[j][2];
                bool f=inRange(x1,y1,x2,y2,r1);
                if(f)helper(bombs,j,k,visited,n);
            }
    }
    void helper(vector<vector<int>>& bombs,int sv,int &k,int n){
        vector<bool> visited(n,false);
        helper(bombs,sv,k,visited,n);
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        //vector<vector<int>> adj(n,vector<int>());
        int ans=0;
        for(int i=0;i<n;i++){
            int k=0;
            helper(bombs,i,k,n);
            ans=max(ans,k);
        }
        return ans;
    }
};