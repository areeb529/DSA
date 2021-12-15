class Solution {
public:
    unordered_map<string,int> mp;
    int maxLengthChain(string &s,int pos,vector<int> &dp){
        if(dp[pos]!=-1)return dp[pos];
        int ans=0;
        for(int i=0;i<s.size();i++){
            string temp;
            if(i==s.size()-1){
                temp=s.substr(0,i);
            }
            else{
                temp=s.substr(0,i)+s.substr(i+1);
            }
            if(mp.count(temp)==1){
                ans=max(ans,maxLengthChain(temp,mp[temp],dp));
            }
        }
        return dp[pos]=1+ans;
    }
    int longestStrChain(vector<string>& words) {
       int n=words.size();
        for(int i=0;i<n;i++){
            mp[words[i]]=i;
        }
        vector<int> dp(n,-1);
        int maxLength=0;
        for(int i=0;i<n;i++){
            maxLength=max(maxLength,maxLengthChain(words[i],i,dp));
        }
        return maxLength;
    }
};