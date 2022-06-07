class Solution {
public:
    #define pii   pair<int,int>
    class compare{
      public:
        bool operator()(const pii &a,const pii &b){
            return a.second>b.second||a.second==b.second&&a.first<b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)mp[nums[i]]++;
        priority_queue<pii,vector<pii>,compare> pq;
        for(auto &i:mp){
            if(pq.size()<k){
                pq.push({i.first,i.second});
            }
            else{
                if(pq.top().second<i.second){
                    pq.pop();
                    pq.push({i.first,i.second});
                }
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};