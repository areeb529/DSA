class Solution {
public:
    string removeDuplicateLetters(string s) {
        // unordered_map<char,int> mp;
        // for(int i=n-1;i>=0;i--){
        //     mp[s[i]]=i;
        // }
        // string res;
        // for(int i=n-1;i>=0;i--){
        //     if(mp[s[i]]==i)
        // }
        stack<char> st;
        int n=s.size();
        unordered_map<char,int> mp;
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                freq[s[i]]--;
                if(freq[s[i]]==0)freq.erase(s[i]);
                mp[s[i]]=i;
            }
            else{
                if(mp.count(s[i])==1){
                    freq[s[i]]--;
                    if(freq[s[i]]==0)freq.erase(s[i]);
                }
                if(s[i]>st.top()&&mp.count(s[i])==0){
                    st.push(s[i]);
                    freq[s[i]]--;
                    if(freq[s[i]]==0)freq.erase(s[i]);
                    mp[s[i]]=i;
                }
                while(!st.empty()&&s[i]<st.top()&&freq.count(st.top())==1&&mp.count(s[i])==0){
                    mp.erase(st.top());
                    st.pop();
                }
                if(mp.count(s[i])==0){
                    st.push(s[i]);
                    freq[s[i]]--;
                    if(freq[s[i]]==0)freq.erase(s[i]);
                    mp[s[i]]=i;   
                }
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
};