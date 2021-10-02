class Solution {
public:
    vector<string> ans;
    void helper(string &s,int i,int n){
        if(i==n){
            ans.push_back(s);
            return;
        }
        if(s[i]>='0'&&s[i]<='9'){
            helper(s,i+1,n);
        }
        else{
            helper(s,i+1,n);
            if(s[i]>='a'&&s[i]<='z'){
                s[i]=s[i]-'a'+'A';
                helper(s,i+1,n);
                s[i]=s[i]-'A'+'a';
            }
            else{
                s[i]=s[i]-'A'+'a';
                helper(s,i+1,n);
                s[i]=s[i]-'a'+'A';
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        helper(s,0,n);
        return ans;
    }
};