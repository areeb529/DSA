class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> res;
        int ct=m*n;
        int i=0,j=0;
        while(ct){
            while(j<n&&matrix[i][j]!=101){
                res.push_back(matrix[i][j]);
                matrix[i][j]=101;
                ct--;
                j++;
            }
            j--;
            i++;
            while(i<m&&matrix[i][j]!=101&&ct){
                res.push_back(matrix[i][j]);
                matrix[i][j]=101;
                ct--;
                i++;
            }
            i--;
            j--;
            while(j>=0&&matrix[i][j]!=101&&ct){
                res.push_back(matrix[i][j]);
                matrix[i][j]=101;
                ct--;
                j--;
            }
            j++;
            i--;
            while(i>=0&&matrix[i][j]!=101&&ct){
                res.push_back(matrix[i][j]);
                matrix[i][j]=101;
                ct--;
                i--;
            }
            i++;
            j++;
        }
        return res;
    }
};