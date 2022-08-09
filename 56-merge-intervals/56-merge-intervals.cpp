class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++){
            if(st.empty())st.push({intervals[i][0],intervals[i][1]});
            else{
                if(intervals[i][0]<=st.top().second){
                    st.top().second=max(st.top().second,intervals[i][1]);
                }
                else st.push({intervals[i][0],intervals[i][1]});
            }
        }
        vector<vector<int>> res;
        while(!st.empty()){
            res.push_back({st.top().first,st.top().second});
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};