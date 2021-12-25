class Solution {
public:
    static bool compare(const vector<int> &a,const vector<int>&b){
        return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>> st;
        sort(intervals.begin(),intervals.end(),compare);
        int n=intervals.size();
        vector<vector<int>> ans;
        st.push(intervals[0]);
        for(int i=1;i<n;i++){
            int x=st.top()[0];
            int y=st.top()[1];
            if(intervals[i][0]>y){
                st.push(intervals[i]);
            }
            else if(intervals[i][0]<=y){
                st.top()[1]=max(st.top()[1],intervals[i][1]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};