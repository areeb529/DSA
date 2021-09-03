class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=rowIndex+1;
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        for(int i=2;i<=numRows;i++){
            vector<int> temp;
            for(int j=0;j<i;j++){
                if(j==0||j==i-1){
                    temp.push_back(1);
                }
                else{
                    int x=ans[0][j]+ans[0][j-1];
                    temp.push_back(x);
                }
            }
            ans.pop_back();
            ans.push_back(temp);
        }
        return ans[0];
    }
};