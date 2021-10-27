class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty())st.push({s[i],1});
            else{
                if(st.top().first!=s[i]){
                    st.push({s[i],1});
                }
                else{
                    if(st.top().second+1==k){
                        int j=k-1;
                        while(j--){
                            st.pop();
                        }
                    }
                    else{
                        st.push({s[i],st.top().second+1});
                    }
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};