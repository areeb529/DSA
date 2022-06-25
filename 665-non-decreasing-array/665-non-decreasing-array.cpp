class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            int diff=nums[i+1]-nums[i];
            if(diff>=0)continue;
            if((i==0||nums[i-1]<=nums[i+1])||(i+1==n-1||nums[i]<=nums[i+2]))cnt++;
            else return false;
        }
        if(cnt>1)return false;
        else return true;
    }
};