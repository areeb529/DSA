class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> ans;
//         for(int k=0;k<n-1;k++){
//             if(k>0&&nums[k]==nums[k-1])continue;
//             int i=k+1,j=n-1;
//             int targetSum=-1*nums[k];
            
//             while(i<j){
//                 vector<int> trip(3);
//                 trip[0]=nums[k];
//                 int sum=nums[i]+nums[j];
//                 if((i>k+1&&nums[i]==nums[i-1])||(sum<targetSum)){
//                     i++;
//                 }
//                 else if((j<n-1&&nums[j]==nums[j+1])||(sum>targetSum)){
//                     j--;
//                 }
//                 else{
//                     trip[1]=nums[i];
//                     trip[2]=nums[j];
//                     ans.push_back(trip);
//                     i++;
//                     j--;
//                 }
//             }
//         }
//         return ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int k=0;k<n-1;k++){
            if(k>0&&nums[k]==nums[k-1])continue;
            int target=-1*nums[k];
            int i=k+1,j=n-1;
            while(i<j){
                int sum=nums[i]+nums[j];
                if(sum<target)i++;
                else if(sum>target)j--;
                else{
                    ans.push_back(vector<int>{nums[k],nums[i],nums[j]});
                    while(i<j&&nums[i]==nums[i+1])i++;
                    while(i<j&&nums[j]==nums[j-1])j--;
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};