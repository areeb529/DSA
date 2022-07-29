class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
       vector<int> pre=height;
       vector<int> suf=height;
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],height[i]);
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=(min(suf[i],pre[i])-height[i]);
        }
        return water;
        
        
    }
};