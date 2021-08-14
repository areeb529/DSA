class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int flag=matrix[0][0];
        bool f1=false;
        bool f2=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        f1=true;
                        continue;
                    }
                    if(j==0){
                        f2=true;
                        continue;
                    }
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int j=0;j<n;j++){
            if(f1){
                matrix[0][j]=0;
            }
            else{
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(f2||flag==0){
                matrix[i][0]=0;
            }
            else{
                break;
            }
        }
        
        
    }
};