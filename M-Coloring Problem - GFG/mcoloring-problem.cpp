// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool canColor(bool graph[101][101],int node,int n,int color,vector<int> &visited){
    for(int i=0;i<n;i++){
        if(graph[node][i]&&visited[i]!=-1){
            if(visited[i]==color)return false;
        }
    }
    return true;
}
bool dfs(bool graph[101][101],int sv,int n,int m,vector<int> &visited){
    for(int color=0;color<m;color++){
        if(canColor(graph,sv,n,color,visited)){
            visited[sv]=color;
            bool ans=true;
            for(int i=0;i<n;i++){
                if(graph[sv][i]&&visited[i]==-1){
                    ans=dfs(graph,i,n,m,visited);
                    if(!ans){
                        visited[sv]=-1;
                        break;
                    }
                }
            }
            if(ans)return true;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> visited(n,-1);
    for(int i=0;i<n;i++){
        if(visited[i]==-1){
            bool ans=dfs(graph,i,n,m,visited);
            if(!ans)return false;
        }
    }
    return true;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends