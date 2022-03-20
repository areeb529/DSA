class Solution {
public:
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        vector<int> cntA(7,0), cntB(7,0), same(7,0);
        for(int i=0;i<n;i++){
            cntA[tops[i]]++;
            cntB[bottoms[i]]++;
            if(tops[i]==bottoms[i])same[tops[i]]++;
        }
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            if(cntA[i]+cntB[i]-same[i]==n){
                ans=min(ans,n-max(cntA[i],cntB[i]));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};