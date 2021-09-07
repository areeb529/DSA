class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int s=0,e=m*n-1;
        while(s<=e){
            int mid=(s+e)/2;
            int i=mid/n,j=mid%n;
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};