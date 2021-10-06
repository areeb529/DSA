class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
         int k=abs(nums[i])-1;
            if(nums[k]>0){
                nums[k]=-nums[k];
            }
            else{
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }
};