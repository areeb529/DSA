class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        set<int> st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    j=0;
                    while(j<n){
                        if(matrix[i][j]==0){
                            st.insert(j);
                        }
                        matrix[i][j]=0;
                        j++;
                    }
                }
            }
        }
        for(auto it:st){
            for(int k=0;k<m;k++){
                matrix[k][it]=0;
            }
        }
    }
};