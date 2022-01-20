class Solution {
public:
    bool canEatAll(vector<int>& piles,int k,int h){
        long time=0;
        for(int i=0;i<piles.size();i++){
            time+=piles[i]/k;
            if(piles[i]%k)time+=1;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas=piles[0];
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxBananas=max(maxBananas,piles[i]);
        }
        int i=1,j=maxBananas;
        int ans=maxBananas;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(canEatAll(piles,mid,h)){
                ans=min(ans,mid);
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};