class Solution {
public:
    set<string> st;
    void helper(int n,string &s){
        if(s.size()==n){
            st.insert(s);
            return;
        }
        if(s.empty()||s[s.size()-1]!='a'){
        s.push_back('a');
        helper(n,s);
        s.pop_back();
        }
        if(s.empty()||s[s.size()-1]!='b'){
        s.push_back('b');
        helper(n,s);
        s.pop_back();
        }
        if(s.empty()||s[s.size()-1]!='c'){
        s.push_back('c');
        helper(n,s);
        s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string s;
        helper(n,s);
        if(st.size()>=k){
            int j=1;
            for(auto i:st){
                if(j==k)return i;
                j++;
            }
        }
        return "";
    }
};