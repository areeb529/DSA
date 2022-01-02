class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        vector<int> mp(60,0);
        for(int i=0;i<n;i++){
            time[i]=time[i]%60;
            mp[time[i]]++;
        }
        int ans=0;
        for(int i=0;i<60;i++){
            if(i==0||i==30){
                ans=ans+(mp[i]*(mp[i]-1))/2;
            }
            else{
                ans=ans+mp[i]*mp[60-i];
                mp[60-i]=0;
            }
        }
        return ans;
    }
};