class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        vector<int> inDegrees(n,0);
        for(auto &i:prerequisites){
            adj[i[1]].push_back(i[0]);
            inDegrees[i[0]]++;
        }
        vector<int> res;
        
        queue<int> pN;
        for(int i=0;i<n;i++){
            if(inDegrees[i]==0)pN.push(i);
        }
        int cnt=0;
        while(!pN.empty()){
            int node=pN.front();
            pN.pop();
            cnt++;
            res.push_back(node);
            for(auto &i:adj[node]){
                inDegrees[i]--;
                if(inDegrees[i]==0)pN.push(i);
            }
        }
        if(cnt==n)return res;
        else return {};
        
    }
};