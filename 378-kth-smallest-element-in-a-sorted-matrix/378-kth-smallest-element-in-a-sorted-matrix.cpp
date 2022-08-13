class Solution {
public:
    int countLessThanEqual(vector<vector<int>>& matrix,int x){
        int cnt=0;
        for(int row=0;row<matrix.size();row++){
            int col=matrix[0].size()-1;
            while(col>=0&&matrix[row][col]>x){
                col--;
            }
            cnt+=(col+1);
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        int low=matrix[0][0],high=matrix[m-1][n-1];
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(countLessThanEqual(matrix,mid)>=k){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};