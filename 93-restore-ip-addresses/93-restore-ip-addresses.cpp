class Solution {
public:
    vector<string> res;
    void helper(string &s,int i,string temp,int k,int n){
        if(i>=n||k==0){
            if(k==0&&i<n&&stoi(s.substr(i))<=255){
                if(s.substr(i).size()>1&&s[i]=='0')return ;
                temp=temp+s.substr(i);
                res.push_back(temp);
            }
            return;
        }
        if(s[i]=='0'){
            temp.push_back(s[i]);
            helper(s,i+1,temp+".",k-1,n);
        }
        else{
            temp.push_back(s[i]);
            helper(s,i+1,temp+".",k-1,n);
            if(i+1<n){
                temp.push_back(s[i+1]);
                helper(s,i+2,temp+".",k-1,n);
            }
            if(i+2<n&&stoi(s.substr(i,3))<=255){
                temp.push_back(s[i+2]);
                helper(s,i+3,temp+".",k-1,n);
            }
        }
        
        
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        if(n<4||n>12)return res;
        string temp;
        helper(s,0,temp,3,n);
        return res;
    }
};