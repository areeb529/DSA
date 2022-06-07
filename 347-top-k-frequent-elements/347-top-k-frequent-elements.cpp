class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)mp[nums[i]]++;
        vector<vector<int>> bucket(n+1);
        for(auto &i:mp){
            bucket[i.second].push_back(i.first);
        }
        vector<int> res;
        for(int i=n;i>=0&&k;i--){
            for(auto &j:bucket[i]){
                res.push_back(j);
                k--;
                if(k==0)break;
            }
        }
        return res;
    }
};