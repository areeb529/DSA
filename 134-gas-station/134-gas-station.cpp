class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int validStartstations=0;
        for(int i=0;i<n;i++){
            if(gas[i]>=cost[i]){
                validStartstations++;
            }
        }
        if(validStartstations==0)return -1;
        int ct=0;
        int currFuel=0;
        int ans=-1;
        for(int i=0;i<n;i=(i+1)%n){
            if(currFuel+gas[i]-cost[i]>=0){
                if(ct==0){
                    validStartstations--;
                }
                if(validStartstations<0)break;
                ct++;
                currFuel+=gas[i]-cost[i];
                if(ct==n){
                    ans=(i+1)%n;
                    break;
                }
            }
            else{
                currFuel=0;
                ct=0;
            }
        }
        return ans;
    }
};