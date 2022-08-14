class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalGas=0;
        int totalCost=0;
        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalGas<totalCost)return -1;
        int startIndex=0;
        if(n==1){
            if(gas[0]>=cost[0])return 0;
            else return -1;
        }
        int curGas=0;
        int ans=-1;
        for(int i=0;i<n;i=(i+1)%n){
            curGas+=gas[i];
            if(curGas-cost[i]<0){
                curGas=0;
                if(startIndex>i)return -1;
                startIndex=(i+1)%n;
                
            }
            else{
                curGas-=cost[i];
                if((i+1)%n==startIndex){
                    ans=startIndex;
                    break;
                }
            }
            
        }
        return ans;
    }
};