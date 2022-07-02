class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod=1e9+7;
        int maxHorizontalDiff=0;
        int maxVerticalDiff=0;
        int m=horizontalCuts.size(),n=verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        for(int i=0;i<=m;i++){
            if(i==0){
                maxHorizontalDiff=horizontalCuts[i];
            }
            else if(i==m){
                maxHorizontalDiff=max(maxHorizontalDiff,h-horizontalCuts[i-1]);
            }
            else{
                maxHorizontalDiff=max(maxHorizontalDiff,horizontalCuts[i]-horizontalCuts[i-1]);
            }
        }
        for(int i=0;i<=n;i++){
            if(i==0){
                maxVerticalDiff=verticalCuts[i];
            }
            else if(i==n){
                maxVerticalDiff=max(maxVerticalDiff,w-verticalCuts[i-1]);
            }
            else{
                maxVerticalDiff=max(maxVerticalDiff,verticalCuts[i]-verticalCuts[i-1]);
            }
        }
        int ans=(((long long)maxHorizontalDiff%mod)*(maxVerticalDiff%mod))%mod;
        return ans;
        
    }
};