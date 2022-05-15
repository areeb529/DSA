class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // int n=candidates.size();
        // int res=0;
        // for(int i=0;i<31;i++){
        //     int ct=0;
        //     for(int j=0;j<n;j++){
        //         if(candidates[j]&(1<<i))ct++;
        //     }
        //     res=max(res,ct);
        // }
        // return res;
        int n=candidates.size();
        int res=0;
        for(int i=0;i<32;i++){
            int ct=0;
            for(int j=0;j<n;j++){
                ct+=(candidates[j]>>i)&1;
            }
            res=max(res,ct);
        }
        return res;
    }
};