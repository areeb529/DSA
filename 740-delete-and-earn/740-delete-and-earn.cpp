class Solution {
public:
    unordered_map<int,int> mp;
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v;
        for(auto i:nums){
            if(mp.count(i)==0){
                mp[i]=i;
                v.push_back(i);
            }
            else mp[i]+=i;
        }
        int n=v.size();
        sort(v.begin(),v.end());
        vector<int> dp(n+2);
        dp[n+1]=0;
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            if(i+1>=n||v[i+1]-v[i]>1)dp[i]=mp[v[i]]+dp[i+1];
            else dp[i]=max(mp[v[i]]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};