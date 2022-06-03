class NumMatrix {
public:
    int m=0,n=0;
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>> temp(m+1,vector<int>(n+1,0));
        mat=temp;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                mat[i][j]=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=mat[row2+1][col2+1]+mat[row1][col1]-mat[row1][col2+1]-mat[row2+1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */