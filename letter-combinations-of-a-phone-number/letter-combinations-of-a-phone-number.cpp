class Solution {
public:
     unordered_map<char,string> mp;
    vector<string> ans;
    void helper(string &digits,int i,string &s,int n){
        if(i==n){
            if(!s.empty())
            ans.push_back(s);
            return;
        }
        for(int j=0;j<mp[digits[i]].size();j++){
            s.push_back(mp[digits[i]][j]);
            helper(digits,i+1,s,n);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string s;
        int n=digits.size();
        helper(digits,0,s,n);
        return ans;
    }
};