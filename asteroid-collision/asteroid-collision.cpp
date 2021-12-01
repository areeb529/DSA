class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()||st.top()<0||st.top()*asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                if(st.top()<-1*asteroids[i]){
                    st.pop();
                    i--;
                }
                else if(st.top()==-1*asteroids[i])st.pop();
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};