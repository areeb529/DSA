class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)return x;
        int s=0,e=x;
        int ans=-1;
        while(s<=e){
            int mid=(e-s)/2+s;
            if(mid>INT_MAX/mid||(mid*mid>x)){
                e=mid-1;
            }
            else if(mid*mid==x){
                ans=mid;
                break;
            }
            else if(mid*mid<x){
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
    }
};