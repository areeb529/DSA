class Solution {
public:
    unordered_map<string,bool> mp;
    // bool wordBreak(string s){
    //     if(s.size()==0)return true;
    //     for(int i=1;i<=s.size();i++){
    //         if(mp.count(s.substr(0,i))==0)continue;
    //         bool f=wordBreak(s.substr(i));
    //         if(f) return true;
    //     }
    //     return false;
    // }
    bool wordBreak(string &s,int i,int k,vector<vector<int>> &dp){
        if(k==0)return 1;
        if(dp[i][k]!=-1)return dp[i][k];
        
        for(int j=i+1;j-i<=k;j++){
            if(mp.count(s.substr(i,j-i))==0)continue;
            int f=0;
            f=wordBreak(s,j,k-j+i,dp);
            if(f)return dp[i][k]=1;
        }
        return dp[i][k]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]=true;
        }
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return wordBreak(s,0,n,dp);
    }
};