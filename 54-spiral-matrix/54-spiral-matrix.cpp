class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // int m=matrix.size();
        // int n=matrix[0].size();
        // vector<int> res;
        // int ct=m*n;
        // int i=0,j=0;
        // while(ct){
        //     while(j<n&&matrix[i][j]!=101){
        //         res.push_back(matrix[i][j]);
        //         matrix[i][j]=101;
        //         ct--;
        //         j++;
        //     }
        //     j--;
        //     i++;
        //     while(i<m&&matrix[i][j]!=101&&ct){
        //         res.push_back(matrix[i][j]);
        //         matrix[i][j]=101;
        //         ct--;
        //         i++;
        //     }
        //     i--;
        //     j--;
        //     while(j>=0&&matrix[i][j]!=101&&ct){
        //         res.push_back(matrix[i][j]);
        //         matrix[i][j]=101;
        //         ct--;
        //         j--;
        //     }
        //     j++;
        //     i--;
        //     while(i>=0&&matrix[i][j]!=101&&ct){
        //         res.push_back(matrix[i][j]);
        //         matrix[i][j]=101;
        //         ct--;
        //         i--;
        //     }
        //     i++;
        //     j++;
        // }
        // return res;
        int m=matrix.size();
        int n=matrix[0].size();
        int rowStart=0,rowEnd=n-1,colStart=0,colEnd=m-1;
        int x=0;
        int ct=m*n;
        vector<int> res;
        
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
            for(i=colEnd-1;ct&&i>=colStart+1;i--){
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