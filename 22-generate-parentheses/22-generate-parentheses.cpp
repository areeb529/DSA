class Solution {
public:
    vector<string> res;
    void helper(int n,int ct1,string &v){
        if(v.size()==2*n){
            if(ct1==0)res.push_back(v);
            return;
        }
        if(ct1<0)return;
        v.push_back('(');
        helper(n,ct1+1,v);
        v.pop_back();
        v.push_back(')');
        helper(n,ct1-1,v);
        v.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string v;
        helper(n,0,v);
        return res;
    }
};