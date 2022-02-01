class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cp=INT_MAX;
        int maxProfit=0;
        for(auto i:prices){
            maxProfit=max(maxProfit,i-cp);
            cp=min(cp,i);
        }
        return maxProfit;
    }
};