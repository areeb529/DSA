class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int sum=0;
        bool f=false;
        int sign=1;
        for(int i=0;i<n;i++){
            if(!f){
                if(s[i]==' ')continue;
                else{
                    f=true;
                    if(s[i]=='0')continue;
                    else if(s[i]>='1'&&s[i]<='9'){
                        sum=sum*10+s[i]-'0';
                    }
                    else if(s[i]=='-'){
                        sign=-1;
                    }
                    else if(s[i]=='+'){
                        sign=1;
                    }
                    else{
                        return sum;
                    }
                }
            }
            else{
                if(s[i]>='0'&&s[i]<='9'){
                    int digit=s[i]-'0';
                    if(sum>INT_MAX/10||sum==INT_MAX/10&&digit>7){
                        if(sign==1)return INT_MAX;
                        else return INT_MIN;
                    }
                    sum=sum*10+digit;
                }
                else{
                    break;
                }
            }
        }
        if(sign==-1)sum=-1*sum;
        return sum;
    }
};