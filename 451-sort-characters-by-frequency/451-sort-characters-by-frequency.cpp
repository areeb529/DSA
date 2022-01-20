class Solution {
public:
    string frequencySort(string s) {
        int cnt[128]={};
        for(auto c:s)cnt[c]++;
        sort(s.begin(),s.end(),[&](char a,char b){
         return cnt[a]>cnt[b]||cnt[a]==cnt[b]&&a<b;
        });
        return s;
    }
};