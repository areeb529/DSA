class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        //vector<int> v(n+1,0);
        unordered_map<int,int> mp;
        int ct=0;
        int maxL=0;
        for(int i=0;i<n;i++){
            if(nums[i])ct++;
            else ct--;
           // v[i+1]=ct;
            if(ct==0){
                maxL=max(maxL,i+1);
                continue;
            }
            if(mp.count(ct)==0)mp[ct]=i;
            else maxL=max(maxL,i-mp[ct]);
        }
        return maxL;
        // int maxL=0;
        // for(int i=1;i<=n;i++){
        //     maxL=max(maxL,mp[v[i]]-i);
        // }
        // maxL=max(maxL,mp[0]);
        // return maxL;
        
    }
};