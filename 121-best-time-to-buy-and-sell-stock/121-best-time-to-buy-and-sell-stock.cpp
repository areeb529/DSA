class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int minStock=prices[0];
        for(int i=1;i<n;i++){
            minStock=min(minStock,prices[i]);
            if(prices[i]>minStock){
                profit=max(profit,prices[i]-minStock);
            }
        }
        return profit;
    }
};