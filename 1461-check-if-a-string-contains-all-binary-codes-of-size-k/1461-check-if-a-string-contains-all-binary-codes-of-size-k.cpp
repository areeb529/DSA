class Solution {
public:
    unordered_set<string> st;
    // void generateCodes(string &t,int i,int k){
    //     if(i==k){
    //         st.insert(t);
    //         return;
    //     }
    //     t[i]='1';
    //     generateCodes(t,i+1,k);
    //     t[i]='0';
    //     generateCodes(t,i+1,k);
    // }
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if(k>n||k==n)return false;
        int i=0,j=0;
        string temp="";
        while(j<n){
            temp=temp+s[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                st.insert(temp);
                temp=temp.substr(1);
                i++;
                j++;
            }
        }
        return st.size()==(1<<k);
    }
};