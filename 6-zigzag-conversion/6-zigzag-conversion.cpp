class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        string ans;
        vector<vector<char>> nums(numRows,vector<char>(n,'*'));
        int k=0;
        int i=0,j=0;
        while(k<n){
            for(i=0;i<numRows&&k<n;i++){
                nums[i][j]=s[k];
                k++;
            }
            if(i==numRows){
                i=numRows-2;
                j++;
            }
            while(i>0&&k<n){
                nums[i][j]=s[k];
                k++;
                i--;
                j++;
            }
        }
        //string ans;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]!='*')ans.push_back(nums[i][j]);
            }
        }
        return ans;
    }
};