class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans;
        int m=strs[0].size();
        for(int i=0;i<m;i++){
            bool f=false;
            for(auto &s:strs){
                if(s[i]!=strs[0][i]){
                    f=true;
                    break;
                }
            }
            if(f)break;
            else ans.push_back(strs[0][i]);
        }
        return ans;
    }
};