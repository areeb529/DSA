class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                if(num[i]!='0')
                st.push(num[i]);
            }
            else{
                if(num[i]<st.top()&&k){
                    st.pop();
                    k--;
                    i--;
                }
                else{
                    st.push(num[i]);
                }
            }
        }
        while(k&&!st.empty()){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)ans="0";
        return ans;
        
    }
};