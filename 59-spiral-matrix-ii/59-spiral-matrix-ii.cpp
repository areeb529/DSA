class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0,right=n-1,top=0,bottom=n-1;
        int ct=n*n;
        int dir=0;
        int k=1;
        vector<vector<int>> grid(n,vector<int>(n));
        while(k<=ct){
            if(dir==0){
                for(int i=left;k<=ct&&i<=right;i++){
                    grid[top][i]=k;
                    k++;
                }
                top++;
            }
            else if(dir==1){
                for(int i=top;k<=ct&&i<=bottom;i++){
                    grid[i][right]=k;
                    k++;
                }
                right--;
            }
            else if(dir==2){
                for(int i=right;k<=ct&&i>=left;i--){
                    grid[bottom][i]=k;
                    k++;
                }
                bottom--;
            }
            else{
                for(int i=bottom;k<=ct&&i>=top;i--){
                    grid[i][left]=k;
                    k++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return grid;
    }
};