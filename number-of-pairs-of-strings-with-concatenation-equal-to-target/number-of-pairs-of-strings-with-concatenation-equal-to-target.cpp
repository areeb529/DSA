class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,string> mp1;
        int n=nums.size();
        int m=target.size();
        for(int i=0;i<m-1;i++){
            mp1[target.substr(0,i+1)]=target.substr(i+1);
        }
        unordered_map<string,int> mp2;
        for(int i=0;i<n;i++){
            mp2[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp2.count(mp1[nums[i]])==1){
                if(mp1[nums[i]]==nums[i]){
                    ans+=mp2[mp1[nums[i]]]-1;
                }
                else{
                    ans+=mp2[mp1[nums[i]]];
                }
            }
        }
        return ans;
    }
};