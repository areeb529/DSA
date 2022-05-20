class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1)return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        vector<int> temp=intervals[0];
        for(auto it:intervals){
            if(temp[1]>=it[0]){
                temp[1]=max(temp[1],it[1]);
            }
            else{
                res.push_back(temp);
                temp=it;
            }
        }
        res.push_back(temp);
        return res;
    }
};