class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> res(n,INT_MIN);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty()||nums[i]<st.top()){
                if(!st.empty())res[i]=st.top();
                st.push(nums[i]);
            }
        }
        int j=0;
        for(int i=n-1;i>=0;i--){
            if(res[i]==INT_MIN){
                int x=nums[i];
                while(j<n&&nums[j]<=x){
                    j++;
                }
                if(j<n)res[i]=nums[j];
                else res[i]=-1;
            }
        }
        return res;
    }
};