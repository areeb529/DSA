class Solution {
public:
    unordered_set<int> visited;
    unordered_set<int> graph;
    int dfs(vector<int>& nums,int sv){
        int ans=1;
        visited.insert(sv);
        int prev=0,next=0;
        if(visited.count(sv-1)==0&&graph.count(sv-1)==1){
            prev=dfs(nums,sv-1);
        }
        if(visited.count(sv+1)==0&&graph.count(sv+1)==1){
            next=dfs(nums,sv+1);
        }
        return ans+prev+next;
        
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            graph.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited.count(nums[i])==0)
            ans=max(ans,dfs(nums,nums[i]));
        }
        return ans;
        
        
    }
};