class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        int N=m+n+1;
        string temp(N,'0');
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<n;i++){
            int cur=0;
            int j=0;
            for(j=0;j<m;j++){
                int sum=(num2[i]-'0')*(num1[j]-'0')+cur+temp[i+j]-'0';
                if(sum>9)cur=sum/10;
                else cur=0;
                temp[i+j]=sum%10+'0';
            }
            if(cur){
                int sum=(temp[i+j]-'0')+cur;
                temp[i+j]=sum+'0';
            }
        }
        int sz=temp.size();
        while(sz!=1&&temp[sz-1]=='0'){
            temp.pop_back();
            sz--;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    
};