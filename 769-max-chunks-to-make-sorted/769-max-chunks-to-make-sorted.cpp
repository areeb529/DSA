class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        int maxM=arr[0];
        for(int i=0;i<n;i++){
            maxM=max(maxM,arr[i]);
            if(i==maxM)ans++;
        }
        return ans;
        
    }
};