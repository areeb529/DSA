class Solution {
public:
    bool canShip(vector<int>& weights, int days,int capacity){
        int ct=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=capacity){
                sum+=weights[i];
            }
            else{
                ct++;
                sum=weights[i];
            }
        }
        return ct<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int packagesWeightSum=0;
        int maxWeightPackage=weights[0];
        for(int i=0;i<n;i++){
            packagesWeightSum+=weights[i];
            maxWeightPackage=max(maxWeightPackage,weights[i]);
        }
        int low=maxWeightPackage,high=packagesWeightSum;
        int res=packagesWeightSum;
        while(low<=high){
            int capacity=low+(high-low)/2;
            if(canShip(weights,days,capacity)){
                res=min(res,capacity);
                high=capacity-1;
            }
            else{
                low=capacity+1;
            }
        }
        return res;
    }
};