class Solution {
public:
    char toLower(char c){
       if(c>='a'&&c<='z'||c>='0'&&c<='9')return c;
       else if(c>='A'&&c<='Z'){
           c='a'+c-'A';
           return c;
       }
        else{
            return '*';
        }
    }
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            char ch1=toLower(s[i]);
            char ch2=toLower(s[j]);
            if(ch1=='*')i++;
            else if(ch2=='*')j--;
            else{
                if(ch1!=ch2)return false;
                i++;
                j--;
            }
        }
        return true;
    }
};