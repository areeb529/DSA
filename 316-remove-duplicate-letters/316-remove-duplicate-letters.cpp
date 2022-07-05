class Solution {
public:
    string removeDuplicateLetters(string s) {
       
        // stack<char> st;
        // int n=s.size();
        // unordered_map<char,int> mp;
        // unordered_map<char,int> freq;
        // for(int i=0;i<n;i++){
        //     freq[s[i]]++;
        // }
        // for(int i=0;i<n;i++){
        //     if(st.empty()){
        //         st.push(s[i]);
        //         freq[s[i]]--;
        //         if(freq[s[i]]==0)freq.erase(s[i]);
        //         mp[s[i]]=i;
        //     }
        //     else{
        //         if(mp.count(s[i])==1){
        //             freq[s[i]]--;
        //             if(freq[s[i]]==0)freq.erase(s[i]);
        //         }
        //         if(s[i]>st.top()&&mp.count(s[i])==0){
        //             st.push(s[i]);
        //             freq[s[i]]--;
        //             if(freq[s[i]]==0)freq.erase(s[i]);
        //             mp[s[i]]=i;
        //         }
        //         while(!st.empty()&&s[i]<st.top()&&freq.count(st.top())==1&&mp.count(s[i])==0){
        //             mp.erase(st.top());
        //             st.pop();
        //         }
        //         if(mp.count(s[i])==0){
        //             st.push(s[i]);
        //             freq[s[i]]--;
        //             if(freq[s[i]]==0)freq.erase(s[i]);
        //             mp[s[i]]=i;   
        //         }
        //     }
        // }
        // string res;
        // while(!st.empty()){
        //     res.push_back(st.top());
        //     st.pop();
        // }
        // reverse(res.begin(),res.end());
        // return res;
        stack<char> st;
        int n=s.size();
        vector<bool> seen(26,false);
        vector<int> lastIndex(26,-1);
        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a'])continue;
            while(!st.empty()&&s[i]<st.top()&&lastIndex[st.top()-'a']>i){
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]-'a']=true;
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