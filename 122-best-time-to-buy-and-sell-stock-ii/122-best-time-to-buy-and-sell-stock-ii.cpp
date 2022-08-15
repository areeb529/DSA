class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int minStockValue=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<minStockValue){
                minStockValue=prices[i];
            }
            else{
                profit+=(prices[i]-minStockValue);
                minStockValue=prices[i];
            }
        }
        return profit;
    }
};