class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return false;
        bool f=false;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                if(f)return false;
            }
            else if(arr[i]>arr[i+1]){
                if(!f)f=true;
            }
            else return false;
        }
        return (arr[0]<arr[1])&&(arr[n-2]>arr[n-1])?true:false;
    }
};