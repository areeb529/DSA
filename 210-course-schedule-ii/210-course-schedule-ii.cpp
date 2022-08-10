class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &i:prerequisites){
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        int cntCourses=0;
        queue<int> pN;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)pN.push(i);
        }
        vector<int> res;
        while(!pN.empty()){
            int front=pN.front();
            res.push_back(front);
            cntCourses++;
            pN.pop();
            for(auto &i:graph[front]){
                indegree[i]--;
                if(indegree[i]==0)pN.push(i);
            }
        }
        if(cntCourses==numCourses)return res;
        else return {};
        
        
    }
};