class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size();
        int n=b.size();
        int cur=0;
        string s;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0;
        while(i<m||j<n||cur){
            int sum=0;
            if(i<m){
                sum+=a[i]-'0';
            }
            if(j<n){
                sum+=b[j]-'0';
            }
            sum=sum+cur;
            if(sum<=1){
                s.push_back(sum+'0');
                cur=0;
            }
            else if(sum==2){
                cur=1;
                s.push_back('0');
            }
            else if(sum==3){
                cur=1;
                s.push_back('1');
            }
            i++;
            j++;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};