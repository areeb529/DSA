class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n=temperatures.size();
        vector<int> v(n,0);
        for(int i=n-1;i>=0;i--){
            int res=0;
            while(!s.empty()&&temperatures[i]>=s.top().first){
                res+=s.top().second;
                s.pop();
            }
            if(!s.empty())res+=1;
            else res=0;
            s.push({temperatures[i],res});
            v[i]=res;
        }
        return v;
    }
};