class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    void partition(string &s,int i,int n,vector<string> &pal){
        if(i==n){
            res.push_back(pal);
            return;
        }
        string palStr;
        for(int j=i;j<n;j++){
            palStr+=s[j];
            if(isPalindrome(s,i,j)){
                pal.push_back(palStr);
                partition(s,j+1,n,pal);
                pal.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> pal;
        partition(s,0,n,pal);
        return res;
    }
};