class Solution {
public:
    int factorial(int n,vector<int> &fact){
        if(n<=1)return 1;
        if(fact[n]!=0)return fact[n];
        return fact[n]=n*factorial(n-1,fact);
    }
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++){
            s.push_back(i+'0');
        }
        vector<int> fact(n+1,0);
        int factor=factorial(n,fact);
        fact[0]=1;
        fact[1]=1;
        if(k==1)return s;
        int idx=0;
        string ans;
        for(int i=1;i<=n;i++){
            if(fact[i]==k){
                reverse(s.begin()+n-i,s.end());
                return s;
            }
            else if(fact[i]<k&&(i==n||fact[i+1]>k)){
                int cnt=k-fact[i];
                reverse(s.begin()+n-i,s.end());
                while(cnt--){
                    int j=n-1;
                    while(j>0&&s[j-1]>s[j])j--;
                    int q=j-1;
                    if(j>0){
                        while(j<n&&s[q]<s[j])j++;
                        swap(s[q],s[j-1]);
                        sort(s.begin()+q+1,s.end());
                    }
                }
                break;
            }
        }
        return s;
    }
};