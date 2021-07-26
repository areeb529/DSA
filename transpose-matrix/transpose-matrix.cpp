class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m1=matrix.size();
        int n1=matrix[0].size();
        int m2=n1;
        int n2=m1;
        vector<vector<int>> ans(m2,vector<int>(n2,0));
        for(int i=0;i<m2;i++){
            for(int j=0;j<n2;j++){
                ans[i][j]=matrix[j][i];
            }
        }
        return ans;
    }
};