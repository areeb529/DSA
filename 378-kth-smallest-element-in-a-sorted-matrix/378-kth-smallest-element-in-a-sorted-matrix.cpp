class Solution {
public:
    int MAX=1e9+1;
    class triplet{
      public:
        int val;
        int i;
        int j;
    };
    class compare{
      public:
        bool operator()(const triplet &a,const triplet &b){
            return a.val>b.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        priority_queue<triplet,vector<triplet>,compare> pq;
        pq.push({matrix[0][0],0,0});
        int ans;
        
        while(true){
            triplet top=pq.top();
            pq.pop();
            int value=top.val;
            //cout<<value<<" "<<k<<endl;
            k--;
            if(k==0){
                ans=value;
                break;
            }
            int x=top.i;
            int y=top.j;
            if(x+1<m&&matrix[x+1][y]!=MAX){
                pq.push({matrix[x+1][y],x+1,y});
                matrix[x+1][y]=MAX;
            }
            if(y+1<n&&matrix[x][y+1]!=MAX){
                pq.push({matrix[x][y+1],x,y+1});
                matrix[x][y+1]=MAX;
            }
        }
        return ans;
    }
};