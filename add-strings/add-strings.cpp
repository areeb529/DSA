class Solution {
public:
    string addStrings(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        int i=m-1,j=n-1;
        int cur=0;
        string s;
        while(cur||i>=0||j>=0){
            int a=0,b=0;
            if(i>=0)
            a=int(num1[i]-'0');
            if(j>=0)
            b=int(num2[j]-'0');
            int value=a+b+cur;
            if(value>9){
                cur=1;
                value=value%10;
            }
            else cur=0;
            s.push_back(char(value+'0'));
            i--,j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};