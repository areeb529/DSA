class Solution {
public:
    static bool compare(pair<int,int> &a,pair<int,int> &b){
        return a.first<b.first||(a.first==b.first&&a.second<b.second);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> intv;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            intv.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(intv.begin(),intv.end(),compare);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(intv[i]);
            }
            else{
                if(st.top().second<intv[i].second){
                    if(st.top().first==intv[i].first){
                        st.pop();
                        st.push(intv[i]);
                    }
                    else st.push(intv[i]);
                }
            }
        }
        return st.size();
    }
};