class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int sminM=INT_MAX;
        // int minM=INT_MAX;
        // int ct=0;
        // for(auto i:nums){
        //     if(i>minM&&sminM!=i){
        //         if(ct==1){
        //           if(i>sminM){
        //               ct++;
        //               return true;
        //           }
        //         else{
        //             sminM=i;
        //         }
        //         }
        //         else{
        //             sminM=i;
        //             ct++;
        //         }
        //     }
        //     minM=min(i,minM);
        // }
        // return false;
        int c1=INT_MAX;
        int c2=INT_MAX;
        for(auto i:nums){
            if(i<c1){
                c1=i;
            }
            else if(i>c1&&i<c2){
                c2=i;
            }
            else if(c2<i){
                return true;
            }
        }
        return false;
    }
};