class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=m*n-1;
        while(i<=j){
            int mid=(j-i)/2+i;
            int midX=mid/n;
            int midY=mid%n;
            if(matrix[midX][midY]==target){
                return true;
            }
            else if(matrix[midX][midY]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return false;
    }
};