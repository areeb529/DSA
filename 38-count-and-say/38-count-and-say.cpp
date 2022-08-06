class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string s=countAndSay(n-1);
        string ans;
        int ct=1;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&s[i]==s[i+1]){
                ct++;
            }
            else if(i==s.size()-1||i+1<s.size()&&s[i]!=s[i+1]){
                ans.push_back('0'+ct);
                ans.push_back(s[i]);
                ct=1;
            }
        }
        return ans;
    }
};