class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        dp.push_back({1});
        for(int i=1;i<numRows;i++){
            int sz=dp[i-1].size()+1;
            vector<int> temp(sz,1);
            dp.push_back(temp);
            for(int j=1;j<sz-1;j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }
        return dp;
        
    }
};