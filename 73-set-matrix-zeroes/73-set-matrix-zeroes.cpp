class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]){
                    if(j==0){
                        col=0;
                    }
                    else matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(j!=0&&(matrix[i][0]==0||matrix[0][j]==0))matrix[i][j]=0;
                else if(j==0&&(matrix[i][0]==0||!col))matrix[i][j]=0;
            }
        }
        
    }
};