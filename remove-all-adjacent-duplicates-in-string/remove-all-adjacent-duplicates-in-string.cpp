class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(!ans.empty()&&s[i]==ans[ans.size()-1]){
                ans.pop_back();
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};