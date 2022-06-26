class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int total=0,sum=0,minSum=INT_MAX,winSize=n-k,i=0,j=0;
        while(j<n){
            sum+=cardPoints[j];
            total+=cardPoints[j];
            if(j-i+1==winSize){
                minSum=min(minSum,sum);
                sum-=cardPoints[i];
                i++;
            }
            j++;
        }
        if(k==n)return total;
        else return total-minSum;
        
        
    }
};