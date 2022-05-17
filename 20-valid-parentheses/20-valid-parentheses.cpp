class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<int> st;
        unordered_map<char,char> mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        for(int i=0;i<n;i++){
            if(s[i]=='}'||s[i]==')'||s[i]==']'){
                if(st.empty()||st.top()!=mp[s[i]])return false;
                else st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty())return true;
        return false;
    }
};