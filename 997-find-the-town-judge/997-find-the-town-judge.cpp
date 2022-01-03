class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> visited(n+1,0);
        for(auto &i:trust){
            visited[i[1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(visited[i]==n-1){
                ans=i;
                break;
            }
        }
        for(auto &i:trust){
            if(ans!=-1&&i[0]==ans){
                ans=-1;
                break;
            }
        }
        return ans;
    }
};