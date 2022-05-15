class Solution {
public:
    
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxOR=0;
        for(int i=0;i<n;i++){
            maxOR|=nums[i];
        }
        int res=0;
        for(int i=0;i<(1<<n);i++){
            int bitOR=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))bitOR=bitOR|nums[j];
            }
            if(bitOR==maxOR)res++;
        }
        return res;
        
    }
};