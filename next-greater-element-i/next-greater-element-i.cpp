class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(n,0);
        stack<int> s;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums1[i]]=i;
        }
            for(int j=m-1;j>=0;j--){
                if(s.empty()){
                    s.push(nums2[j]);
                    if(mp.count(nums2[j])==1){
                        ans[mp[nums2[j]]]=-1;
                    }
                }
                else if(nums2[j]<s.top()){
                    if(mp.count(nums2[j])==1){
                        ans[mp[nums2[j]]]=s.top();
                    }
                    s.push(nums2[j]);
                }
                else if(nums2[j]>s.top()){
                    while(!s.empty()&&nums2[j]>s.top()){
                        s.pop();
                    }
                    if(s.empty()){
                        if(mp.count(nums2[j])==1){
                            ans[mp[nums2[j]]]=-1;
                        }
                        s.push(nums2[j]);
                    }
                    else{
                        if(mp.count(nums2[j])==1){
                            ans[mp[nums2[j]]]=s.top();
                        }
                        s.push(nums2[j]);
                    }
                }
            }
        return ans;
    }
};