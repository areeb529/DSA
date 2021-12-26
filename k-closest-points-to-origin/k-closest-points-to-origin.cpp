class Solution {
public:
     bool comp(const vector<int> &a,vector<int> &b){
        long x=((long)a[0]*a[0]+(long)a[1]*a[1]);
        long y=((long)b[0]*b[0]+(long)b[1]*b[1]);
        return x>y;
    }
    class compare{
      public:
        bool operator()(const vector<int> &a,vector<int> &b){
        long x=((long)a[0]*a[0]+(long)a[1]*a[1]);
        long y=((long)b[0]*b[0]+(long)b[1]*b[1]);
        return x<y;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            if(pq.size()<k)pq.push(points[i]);
            else {
                if(comp(pq.top(),points[i])){
                    pq.pop();
                    pq.push(points[i]);
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};