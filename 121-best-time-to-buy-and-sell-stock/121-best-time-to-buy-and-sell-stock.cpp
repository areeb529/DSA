class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> minArray(n);
        vector<int> maxArray(n);
        int minM=INT_MAX;
        int maxM=INT_MIN;
        for(int i=0;i<n;i++){
            minM=min(minM,prices[i]);
            minArray[i]=minM;
            maxM=max(maxM,prices[n-i-1]);
            maxArray[n-i-1]=maxM;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,maxArray[i+1]-minArray[i]);
        }
        return ans;
    }
};