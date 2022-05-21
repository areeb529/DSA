class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int boughtStockPrice=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]>boughtStockPrice){
                ans=ans+prices[i]-boughtStockPrice;
            }
            boughtStockPrice=prices[i];
        }
        return ans;
        
    }
};