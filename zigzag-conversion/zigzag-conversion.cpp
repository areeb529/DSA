class Solution {
public:
    string convert(string s, int numRows) {
        int m=numRows;
        int n=s.size();
        int k=0;
        if(m==1||n==1)return s;
        string ans;
        vector<vector<char>> nums(m,vector<char>(n));
        int j=0;
        while(k<n){
            for(int i=0;i<m-1&&k<n;i++){
                nums[i][j]=s[k];
                k++;
            }
            for(int i=m-1;i>0&&k<n;i--){
                nums[i][j]=s[k];
                j++;
                k++;
            }
        }
        int sz=j;
        for(int i=0;i<m;i++){
            for(j=0;j<=sz;j++){
                if(nums[i][j])
                ans.push_back(nums[i][j]);
            }
        }
        return ans;
    }
};