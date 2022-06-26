class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> pre(n+1,0);
        vector<int> suf(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=cardPoints[i]+pre[i];
            suf[n-i-1]=cardPoints[n-i-1]+suf[n-i];
        }
        int i=-1;
        int maxScore=0;
        while(i<k){
            int j=n-k+i+1;
            int score=pre[i+1]+suf[j];
            maxScore=max(score,maxScore);
            i++;
        }
        return maxScore;
    }
};