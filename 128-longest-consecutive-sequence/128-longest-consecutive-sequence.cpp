class Solution {
public:
    int dfs(unordered_map<int,int> &mp,int num){
        if(mp[num]!=-1)return mp[num];
        int ans=1;
        if(mp.count(num-1)==1){
            ans+=dfs(mp,num-1);
        }
        return mp[num]=ans;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int res=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]=-1;
        }
        for(auto &i:mp){
            res=max(res,dfs(mp,i.first));
        }
        return res;
    }
};