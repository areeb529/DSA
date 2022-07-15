class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string word;
        string ans;
        while(ss>>word){
            reverse(word.begin(),word.end());
            ans=ans+word;
            ans.push_back(' ');
        }
        while(ans.size()>0&&ans[ans.size()-1]==' ')ans.pop_back();
        return ans;
        
        
    }
};