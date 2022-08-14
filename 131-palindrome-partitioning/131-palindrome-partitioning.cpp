class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string &s,int start,int end,vector<string> &sub){
        if(start>end){
            res.push_back(sub);
            return;
        }
        string temp;
        for(int i=start;i<=end;i++){
            temp+=s[i];
            if(isPalindrome(temp)){
                sub.push_back(temp);
                helper(s,i+1,end,sub);
                sub.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> sub;
        helper(s,0,n-1,sub);
        return res;
    }
};