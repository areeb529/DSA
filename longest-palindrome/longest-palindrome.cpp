class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp.count(s[i])==0){
                mp[s[i]]=1;
            }
            else{
                mp[s[i]]++;
            }
        }
        int k=0;
        bool f=false;
        for(auto it:mp){
            if(it.second%2){
              k+=it.second-1;
                f=true;
            }
            else if(it.second%2==0){
                k+=it.second;
            }
        }
        if(f)k++;
        return k;
    }
};