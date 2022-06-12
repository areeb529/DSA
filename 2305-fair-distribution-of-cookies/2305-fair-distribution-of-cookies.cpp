class Solution {
public:

    int minUnfairness=INT_MAX;
    void helper(vector<int>& cookies,int i,int k,int cnt,int n,vector<int> &cookieVector,int maxDistributed){
        if(i==n){
            if(cnt==0)minUnfairness=min(minUnfairness,maxDistributed);
            return;
        }
        if(cnt<0)return;
        for(int j=0;j<k;j++){
            if(cookieVector[j]==0)cnt--;
            int temp=maxDistributed;
            cookieVector[j]+=cookies[i];
            maxDistributed=max(maxDistributed,cookieVector[j]);
            helper(cookies,i+1,k,cnt,n,cookieVector,maxDistributed);
            maxDistributed=temp;
            cookieVector[j]-=cookies[i];
            if(cookieVector[j]==0)cnt++;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int> cookieVector(k,0);
        helper(cookies,0,k,k,n,cookieVector,0);
        return minUnfairness;
        
    }
};