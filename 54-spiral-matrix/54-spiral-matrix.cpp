class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int ct=m*n;
        vector<int> res;
        int rowStart=0,rowEnd=n-1,colStart=0,colEnd=m-1;
        while(ct){
            int i=rowStart,j=colStart;
            for(j=rowStart;ct&&j<=rowEnd;j++){
                res.push_back(matrix[i][j]);
                ct--;
            }
            j--;
            for(i=colStart+1;ct&&i<=colEnd;i++){
                res.push_back(matrix[i][j]);
                ct--;
            }
            i--;
            for(j=rowEnd-1;ct&&j>=rowStart;j--){
                res.push_back(matrix[i][j]);
                ct--;
            }
            j++;
            for(i=colEnd-1;ct&&i>colStart;i--){
                res.push_back(matrix[i][j]);
                ct--;
            }
            i++;
            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
        }
        return res;
    }
};