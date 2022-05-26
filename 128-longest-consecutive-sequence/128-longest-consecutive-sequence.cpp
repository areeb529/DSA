class Solution {
public:
    unordered_set<int> st;
    int dfs(int x){
        st.erase(x);
        int right=0,left=0;
        if(st.count(x+1)==1)right=dfs(x+1);
        if(st.count(x-1)==1)left=dfs(x-1);
        return left+1+right;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxM=0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            maxM=max(maxM,dfs(nums[i]));
        }
        return maxM;
                         
    }
};