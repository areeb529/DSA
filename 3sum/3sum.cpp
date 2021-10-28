class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int k=0;k<n-1;k++){
            if(k>0&&nums[k]==nums[k-1])continue;
            int i=k+1,j=n-1;
            int targetSum=-1*nums[k];
            
            while(i<j){
                vector<int> trip(3);
                trip[0]=nums[k];
                int sum=nums[i]+nums[j];
                if((i>k+1&&nums[i]==nums[i-1])||(sum<targetSum)){
                    i++;
                }
                else if((j<n-1&&nums[j]==nums[j+1])||(sum>targetSum)){
                    j--;
                }
                else{
                    trip[1]=nums[i];
                    trip[2]=nums[j];
                    ans.push_back(trip);
                    i++;
                    j--;
                }
                // if(sum==targetSum){
                //     if(i>0&&nums[i]==nums[i-1]&&j<n-1&&nums[j]==nums[j+1]){
                //         i++;
                //         j++;
                //         continue;
                //     }
                //     trip[1]=nums[i];
                //     trip[2]=nums[j];
                //     ans.push_back(trip);
                //     i++;
                //     j--;
                // }
                // else if(sum<targetSum)i++;
                // else j--;
            }
        }
        return ans;
    }
};