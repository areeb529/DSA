class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i-1>=0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j-1>i&&nums[j]==nums[j-1])continue;
                int x=j+1,y=n-1;
                while(x<y){
                    // if(x-1>j&&nums[x]==nums[x-1]&&x+1<y)x++;
                    // if(x<y-1&&y+1<n&&nums[y]==nums[y+1])y--;
                    if((long)nums[i]+nums[j]+nums[x]+nums[y]==(long)target){
                        res.push_back({nums[i],nums[j],nums[x],nums[y]});
                        while(x+1<n&&nums[x]==nums[x+1])x++;
                        while(x<y-1&&nums[y-1]==nums[y])y--;
                        x++;
                        y--;   
                        
                    }
                    else if((long)nums[i]+nums[j]+nums[x]+nums[y]<(long)target){
                        while(x+1<n&&nums[x]==nums[x+1])x++;
                        x++;
                    }
                    else{
                        while(x<y-1&&nums[y-1]==nums[y])y--;
                        y--;
                    }
                }
            }
        }
        return res;
    }
};