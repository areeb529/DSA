class Solution {
public:
    int maxPower(string s) {
        int ct=1;
        int ans=0;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                ct++;
            }
            else{
                ct=1;
            }
            ans=max(ans,ct);
        }
        ans=max(ans,ct);
        return ans;
    }
};