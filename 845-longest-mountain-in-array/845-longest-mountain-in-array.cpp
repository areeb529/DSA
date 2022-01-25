class Solution {
public:
    int longestMountain(vector<int>& arr) {
      bool f=false;
        int n=arr.size();
        if(n<3)return 0;
        int ct=1;
        int res=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                if(!f)ct++;
                else {
                    f=false;
                    ct=1;
                    ct++;
                }
            }
            else if(arr[i]>arr[i+1]){
                if(!f){
                    if(ct!=1){
                        ct++;
                        f=true;
                        res=max(res,ct);
                    }
                }
                else{
                    ct++;
                    res=max(res,ct);
                }
            }
            else{
                ct=1;
                f=false;
            }
        }
        return res;
    }
};