class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            if(mp.count(s[j])==0){
                ans=max(ans,j-i+1);
            }
            else{
                while(i<=mp[s[j]]){
                    mp.erase(s[i]);
                    i++;
                }
            }
            mp[s[j]]=j;
            j++;
        }
        return ans;
    }
};