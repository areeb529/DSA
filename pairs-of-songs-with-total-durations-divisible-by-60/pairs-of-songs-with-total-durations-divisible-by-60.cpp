class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        vector<int> mp(60,0);
        int res=0;
        for(auto t:time){
            res+=mp[(60-t%60)%60];
            mp[t%60]++;
        }
        return res;
    }
};