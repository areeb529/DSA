class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int ans=0;
        int n=piles.size();
        int i=0,j=n-1;
        while(i+1<j){
            ans+=piles[i+1];
            i+=2;
            j-=1;
        }
        return ans;
    }
};