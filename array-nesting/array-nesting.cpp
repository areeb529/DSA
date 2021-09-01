class Solution {
public:
    unordered_map<int,int> mp;
    int link(vector<int>& nums,int k,vector<bool> &visited){
        int ct=0;
        ct++;
        visited[nums[k]]=true;
        if(!visited[k])ct+=link(nums,mp[k],visited);
        if(!visited[nums[nums[k]]])ct+=link(nums,nums[k],visited);
        return ct;
    }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        vector<bool> visited(n,false);
        int ans=1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int l=link(nums,i,visited);
                ans=max(ans,l);
            }
        }
        return ans;
    }
};