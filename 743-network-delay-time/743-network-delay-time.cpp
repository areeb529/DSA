class Solution {
public:
    class compare{
      public:
        bool operator()(const pair<int,int> &a,const pair<int,int> &b){
            return a.first>b.first||(a.first==b.first&&a.second>b.second);
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(n==1)return 0;
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        
        vector<vector<pair<int,int>>> graph(n);
        for(auto &i:times){
            graph[i[0]-1].push_back({i[1]-1,i[2]});
        }
        vector<bool> visited(n,false);
        pq.push({0,k-1});
        dist[k-1]=0;
        int totalNodesVisited=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            if(visited[node])continue;
            for(auto &i:graph[node]){
                if(distance+i.second<dist[i.first]){
                    dist[i.first]=distance+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
            visited[node]=true;
            totalNodesVisited++;
            if(totalNodesVisited==n)break;
        }
        int minTime=0;
        for(int i=0;i<n;i++){
            minTime=max(dist[i],minTime);
        }
        if(minTime==INT_MAX)minTime=-1;
        return minTime;
    }
};