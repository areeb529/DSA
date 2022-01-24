class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int res=0;
        for(auto &n:nums){
            if(st.find(n)==st.end())continue;
            st.erase(n);
            int ct=1;
            int prev=n-1,next=n+1;
            while(st.find(prev)!=st.end()){
                ct++;
                st.erase(prev);
                prev--;
            }
            while(st.find(next)!=st.end()){
                ct++;
                st.erase(next);
                next++;
            }
            res=max(res,ct);
        }
        return res;
    }
};