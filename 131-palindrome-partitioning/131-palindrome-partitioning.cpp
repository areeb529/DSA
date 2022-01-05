class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &s){
        string temp=s;
        reverse(temp.begin(),temp.end());
        return s==temp;
    }
    void partition(string &s,int i,int j,vector<string> &v){
        if(i>j){
            ans.push_back(v);
            return;
        }
        for(int k=i;k<=j;k++){
            string temp=s.substr(i,k-i+1);
            if(isPalindrome(temp)){
                v.push_back(temp);
                partition(s,k+1,j,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> v;
        partition(s,0,n-1,v);
        return ans;
    }
};