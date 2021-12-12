class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        int k=2*time+1;
        vector<int> ans;
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int ct=0;
        for(int i=0;i<n;i++){
            if(i==0||security[i-1]>=security[i]){
                ct++;
            }
            else ct=1;
             prefix[i]=ct;
        }
        ct=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1||security[i]<=security[i+1]){
                ct++;
            }
            else ct=1;
            suffix[i]=ct;
        }
        for(int i=0;i<n;i++){
            if((prefix[i]>=(k/2+1))&&(suffix[i]>=(k/2+1)))ans.push_back(i);
        }
        return ans;
    }
};