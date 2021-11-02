class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
     int n=nums.size();
     vector<int> target(n,-1);
     for(int i=0;i<n;i++){
         int idx=index[i];
         if(target[idx]>=0){
             for(int j=n-1;j>idx;j--){
                 target[j]=target[j-1];
             }
         }
         target[idx]=nums[i];
     }
        return target;
        
    }
};