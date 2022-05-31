class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        int preMax=height[0];
        int suMax=height[n-1];
        for(int i=0;i<n;i++){
            preMax=max(preMax,height[i]);
            suMax=max(suMax,height[n-i-1]);
            pre[i]=preMax;
            suff[n-i-1]=suMax;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(pre[i],suff[i])-height[i]);
        }
        return ans;
    }
};