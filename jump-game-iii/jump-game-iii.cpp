class Solution {
public:
    int helper(vector<int>& arr, int start,int n,vector<bool> &visited){
         if(arr[start]==0){
            return 1;
         }
        visited[start]=true;
        int opt1=0,opt2=0;
        if(start+arr[start]<n&&!visited[start+arr[start]]){
            opt1=helper(arr,start+arr[start],n,visited);
            if(opt1)return 1;
        }
        if(start-arr[start]>=0&&!visited[start-arr[start]]){
            opt2=helper(arr,start-arr[start],n,visited);
            if(opt2)return 1;
        }
        return 0;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        bool f=false;
        for(auto i:arr){
            if(i==0){
                f=true;
                break;
            }
        }
        if(!f)return false;
        vector<bool> visited(n,false);
        return helper(arr,start,n,visited);
    }
};