class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num=to_string(n);
        int d=digits.size(),k=num.size();
        unordered_set<char> st;
        for(int i=0;i<d;i++){
            st.insert(digits[i][0]);
        }
        int ans=0;
        for(int i=1,p=1;i<k;i++){
            ans=ans+d*p;
            p*=d;
        }
        for(int i=0;i<k;i++){
            int j=0;
            for(j=0;j<d&&digits[j][0]<num[i];j++){
            }
            if(i==k-1&&st.count(num[i])==1)ans+=1;
            if(i==0||st.count(num[i-1])==1)
            ans=ans+j*((int)pow(d,k-i-1));
            else break;
        }
        return ans;
    }
};