class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int minD=INT_MAX;
        for(int i=0;i<n-1;i++){
            minD=min(minD,arr[i+1]-arr[i]);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==minD){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};