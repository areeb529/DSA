class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        if(m>n)return false;
        unordered_map<char,int> mp;
        for(int i=0;i<m;i++){
            if(mp.count(s1[i])==0)mp[s1[i]]=1;
            else mp[s1[i]]++;
        }
        int count=mp.size();
        int k=m;
        int i=0,j=0;
        while(j<n){
            if(mp.count(s2[j])==1){
                    mp[s2[j]]--;
                    if(mp[s2[j]]==0){
                        count--;
                    }
                    if(count==0)return true;
                }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(mp.count(s2[i])==1){
                    if(mp[s2[i]]==0)count++;
                    mp[s2[i]]++;
                }
                i++;
                j++;
            }
        }
        return false;
        
    }
};