class Solution {
public:
    string addBinary(string a, string b) {
     reverse(a.begin(),a.end());
     reverse(b.begin(),b.end());
        string s;
        int m=a.size(),n=b.size();
     int cur=0;
        int i=0,j=0;
        while(cur==1||i<m||j<n){
            int x=0,y=0;
            if(i<m)x=a[i]-'0';
            if(j<n)y=b[j]-'0';
            int val=x+y+cur;
            if(val>1)cur=1;
            else cur=0;
            if(val==0||val==2)s.push_back('0');
            else s.push_back('1');
            i++,j++;
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
};