class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sminM=INT_MAX;
        int minM=INT_MAX;
        int ct=0;
        for(auto i:nums){
            if(i>minM&&sminM!=i){
                if(ct==1){
                  if(i>sminM){
                      ct++;
                      return true;
                  }
                else{
                    sminM=i;
                }
                }
                else{
                    sminM=i;
                    ct++;
                }
            }
            minM=min(i,minM);
        }
        return false;
        
    }
};