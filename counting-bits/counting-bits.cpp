class Solution {
public:
    int countBits(int n,vector<int>&ans){
        if(n==0){
            ans[0]=0;
            return 0;
        }
        if(ans[n]!=-1)return ans[n];
        if(n&1){
            if(ans[n-1]!=-1)return ans[n]=1+ans[n-1];
            ans[n-1]=countBits(n-1,ans);
            return ans[n]=1+countBits(n-1,ans);
        }
        else{
            if(ans[n>>1]!=-1)return ans[n]=ans[n>>1];
            ans[n>>1]=countBits(n>>1,ans);
            return ans[n]=countBits(n>>1,ans);
        }
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,-1);
        for(int i=0;i<=n;i++){
            if(ans[i]==-1)countBits(i,ans);
        }
        return ans;
    }
};