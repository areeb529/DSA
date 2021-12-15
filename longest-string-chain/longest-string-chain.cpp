class Solution {
public:
    unordered_map<string,int> mp;
    static bool compare(const string &s1,const string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
       
        
        int n=words.size();
        sort(words.begin(),words.end(),compare);
        for(int i=0;i<n;i++){
            mp[words[i]]=1;
        }
        int maxLength=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                string temp=words[i].substr(0,j)+words[i].substr(j+1);
                if(mp.count(temp)==1){
                    mp[words[i]]=max(mp[words[i]],1+mp[temp]);
                }
            }
            maxLength=max(maxLength,mp[words[i]]);
        }
        return maxLength;
        
    }
};