class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        priority_queue<int> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pq.size()<k)pq.push(matrix[i][j]);
                else {
                    if(pq.top()>matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        int ans=pq.top();
        return ans;
        
    }
};