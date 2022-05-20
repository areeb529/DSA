class Solution {
public:
    static bool compare(const pair<int,int> &a,const pair<int,int> &b){
        return a.first<b.first||a.first==b.first&&a.second<b.second;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        stack<pair<int,int>> st;
        vector<pair<int,int>> nums(n);
        for(int i=0;i<n;i++){
            nums[i]={intervals[i][0],intervals[i][1]};
        }
        sort(nums.begin(),nums.end(),compare);
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(nums[i]);
            }
            else{
                if(nums[i].first<=st.top().second){
                    st.top().second=max(nums[i].second,st.top().second);
                }
                else{
                    st.push(nums[i]);
                }
            }
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back({st.top().first,st.top().second});
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};