class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int maxReach=0;
        int ct=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int reach=mp[s[i]];
            maxReach=max(reach,maxReach);
            if(i<=maxReach){
                ct++;
                if(i==maxReach){
                    ans.push_back(ct);
                    maxReach=0;
                    ct=0;
                }
            }
        }
        return ans;
    }
};