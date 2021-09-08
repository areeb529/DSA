class Solution {
public:
    unordered_map<int,int> mp;
    int helper(vector<int> &v,int i, vector<int> &dp){
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int a=0,b=0;
        if(i+1>=v.size()||v[i+1]-v[i]>1){
        a=v[i]*mp[v[i]]+helper(v,i+1,dp);    
        }
        else{
        a=v[i]*mp[v[i]]+helper(v,i+2,dp);
        b=helper(v,i+1,dp);
        }
        return dp[i]=max(a,b);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v;
        for(auto i:nums){
            if(mp.count(i)==0){
                mp[i]=1;
                v.push_back(i);
            }
            else mp[i]++;
        }
        int n=v.size();
        sort(v.begin(),v.end());
        vector<int> dp(n+1,-1);
        return helper(v,0,dp);
    }
};