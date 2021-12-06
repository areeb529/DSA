class Solution {
public:
    unordered_map<int,int> mp;
    int findCost(int maxCoinPosition){
        int cost=0;
        for(auto &i:mp){
            if(i.first==maxCoinPosition)continue;
            if(abs(i.first-maxCoinPosition)&1)cost+=i.second;
        }
        return cost;
    }
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        for(int i=0;i<n;i++){
            mp[position[i]]++;
        }
        int maxCoins=0;
        for(auto &i:mp){
            maxCoins=max(i.second,maxCoins);
        }
        int minCost=INT_MAX;
        for(auto &i:mp){
            minCost=min(minCost,findCost(i.first));
        }
        return minCost;
        
    }
};