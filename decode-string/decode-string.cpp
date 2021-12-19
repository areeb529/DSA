class Solution {
public:
    string helper(string &s,int i,int j){
        if(i>j)return "";
        if(i==j)return s.substr(i,j-i+1);
        int num=0;
        string ans;
        for(int k=i;k<=j;k++){
            if(s[k]>='0'&&s[k]<='9'){
                num=num*10+s[k]-'0';
            }
            else if(s[k]=='['){
                int start=k+1;
                int ct=0;
                while(k<=j){
                    if(s[k]=='[')ct--;
                    if(s[k]==']')ct++;
                    if(ct==0)break;
                    k++;
                }
                int end=k-1;
                string decodedString=helper(s,start,end);
                while(num--){
                    ans+=decodedString;
                }
            }
            else if(s[k]>='a'&&s[k]<='z'){
                ans.push_back(s[k]);
            }
        }
        return ans;
    }
    void helper(string &s,int i,int j,string &ans){
        if(i>j)return;
        int num=0;
        for(int k=i;k<=j;k++){
            if(s[k]>='0'&&s[k]<='9'){
                num=num*10+s[k]-'0';
            }
            else if(s[k]=='['){
                int start=k+1;
                int ct=0;
                while(k<=j){
                    if(s[k]=='[')ct--;
                    if(s[k]==']')ct++;
                    if(ct==0)break;
                    k++;
                }
                int end=k-1;
        
                while(num--){
                    helper(s,start,end,ans);
                }
                num=0;
            }
            else if(s[k]>='a'&&s[k]<='z'){
                ans.push_back(s[k]);
            }
        }
        
    }
    string decodeString(string s) {
        int n=s.size();
        //return helper(s,0,n-1);
        string ans;
        helper(s,0,n-1,ans);
        return ans;
    }
};