class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return 0;
        int res=0;
        int up=0,down=0;
        for(int i=1;i<n;i++){
            if(down&&arr[i-1]<arr[i]||arr[i-1]==arr[i])up=0,down=0;
            up+=arr[i-1]<arr[i];
            down+=arr[i-1]>arr[i];
            if(up&&down)res=max(res,1+up+down);
        }
        return res;
    }
};