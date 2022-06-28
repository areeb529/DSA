class Solution {
public:
    
    int minDeletions(string s) {
        int n=s.size();
        map<char,int> mp;
        for(auto &i:s){
            mp[i]++;
        }
        vector<int> nums;
        for(auto &i:mp){
            nums.push_back(i.second);
        }
        int N=nums.size();
        int deletions=0;
        sort(nums.begin(),nums.end());
        // cout<<N<<endl;
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        for(int i=N-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                if(nums[i+1]==1){
                    deletions+=nums[i];
                    nums[i]=1;
                }
                else{
                    deletions+=(nums[i]-nums[i+1]+1);
                    nums[i]-=(nums[i]-nums[i+1]+1);
                }
            }
        }
        return deletions;
    }
};