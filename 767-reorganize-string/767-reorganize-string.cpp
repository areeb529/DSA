class Solution {
public:
    class compare{
        public:
        bool operator()(const pair<char,int>&a, const pair<char,int>&b){
            return a.second<b.second;
        }
    };
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]>(n+1)/2)return "";
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        for(auto &i:mp){
            pq.push({i.first,i.second});
        }
        
        int cnt=(n+1)/2;
        int k=0;
        bool flag=false;
        while(cnt){
            pair<char,int> top=pq.top();
            pq.pop();
            char ch=top.first;
            int freq=top.second;
            while(k<n&&freq--&&cnt--){
                s[k]=ch;
                k+=2;
            }
            if(cnt==0){
                if(freq){
                    k=1;
                    flag=true;
                    while(freq--&&k<n){
                        s[k]=ch;
                        k+=2;
                    }
                }
                break;
            }
        }
        if(!flag)k=1;
        while(!pq.empty()){
            pair<char,int> top=pq.top();
            pq.pop();
            char ch=top.first;
            int freq=top.second;
            while(freq--&&k<n){
                s[k]=ch;
                k+=2;
            }
        }
        return s;
        
    }
};