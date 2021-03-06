class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int> mp;
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty()&&nums2[i]>=st.top())st.pop();
            if(st.empty())mp[nums2[i]]=-1;
            else {
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<n;i++){
            res[i]=mp[nums1[i]];
        }
        return res;
        
    }
};