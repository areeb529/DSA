class Solution {
public:
    
   int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suf(n,0);
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<n;i++){
            if(i-1>=0)
            pre[i]=pre[i-1]+nums[i];
            else pre[i]=nums[i];
            mp1[pre[i]]=i;
        }
        for(int i=n-1;i>=0;i--){
            if(i+1<n){
                suf[i]=suf[i+1]+nums[i];
            }
            else{
                suf[i]=nums[i];
            }
            mp2[suf[i]]=i;
        }
        int ans=INT_MAX;
        for(int i=0;i<n&&pre[i]<=x;i++){
            if(mp2.count(x-pre[i])==1&&mp2[x-pre[i]]>i){
                ans=min(ans,i+1+n-mp2[x-pre[i]]);
            }
            if(pre[i]==x){
                ans=min(ans,i+1);
            }
        }
        for(int i=n-1;i>=0&&suf[i]<=x;i--){
            if(mp1.count(x-suf[i])==1&&mp1[x-suf[i]]<i){
                ans=min(ans,n-i+mp1[x-suf[i]]+1);
            }
            if(suf[i]==x){
                ans=min(ans,n-i);
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};