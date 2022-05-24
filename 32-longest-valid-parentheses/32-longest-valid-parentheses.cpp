class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<pair<char,int>> st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }
            else{
                if(!st.empty()&&st.top().first=='('){
                    st.pop();
                    if(st.empty()){
                        ans=max(ans,i+1);
                    }
                    else{
                        ans=max(ans,i-st.top().second);
                    }
                }
                else{
                    st.push({s[i],i});
                }
            }
        }
        return ans;
        
    }
};