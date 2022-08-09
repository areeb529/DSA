class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int n=intervals.size();
      vector<vector<int>> res;
      sort(intervals.begin(),intervals.end());
       vector<int> newInterval=intervals[0];
        for(auto &it:intervals){
            if(it[0]<=newInterval[1]){
                newInterval[1]=max(newInterval[1],it[1]);
            }
            else{
                res.push_back(newInterval);
                newInterval=it;
            }
        }
        res.push_back(newInterval);
        return res;
    }
};