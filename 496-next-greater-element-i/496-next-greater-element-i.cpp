class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++){
            mp[nums1[i]]=i;
        }
        vector<int> res(m,-1);
        stack<int> st;
        for(int j=n-1;j>=0;j--){
            while(!st.empty()&&nums2[j]>st.top()){
             st.pop();   
            }
            if(st.empty()||nums2[j]<st.top()){
                if(!st.empty()&&mp.count(nums2[j])==1)
                res[mp[nums2[j]]]=st.top();
                st.push(nums2[j]);
            }
        }
        return res;
        
    }
};