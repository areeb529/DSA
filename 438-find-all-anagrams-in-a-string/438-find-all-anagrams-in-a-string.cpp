class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        int cnt=0;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[p[i]]++;
        }
        cnt=mp.size();
        int i=0,j=0;
        while(j<n){
            if(mp.count(s[j])==1){
                mp[s[j]]--;
                if(mp[s[j]]==0)cnt--;
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(cnt==0)ans.push_back(i);
                if(mp.count(s[i])==1){
                    if(mp[s[i]]==0)cnt++;
                    mp[s[i]]++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};