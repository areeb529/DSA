class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++){
            s.push_back(i+'0');
        }
        k--;
        while(k--){
            int i=n-1;
            while(i>0&&s[i-1]>s[i])i--;
            if(i>0){
                int j=i;
                while(j<n&&s[i-1]<s[j])j++;
                swap(s[i-1],s[j-1]);
                sort(s.begin()+i,s.end());
            }
        }
        return s;
        
    }
};