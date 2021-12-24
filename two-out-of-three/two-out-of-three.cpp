class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> st2;
        for(int i=0;i<nums2.size();i++){
            st2.insert(nums2[i]);
        }
        unordered_set<int> st3;
        for(int i=0;i<nums3.size();i++){
            st3.insert(nums3[i]);
        }
        unordered_set<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(st2.count(nums1[i])==1){
                ans.insert(nums1[i]);
            }
            else if(st3.count(nums1[i])==1){
                ans.insert(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(st3.count(nums2[i])==1){
                ans.insert(nums2[i]);
            }
        }
        vector<int> res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
        
        
    }
};