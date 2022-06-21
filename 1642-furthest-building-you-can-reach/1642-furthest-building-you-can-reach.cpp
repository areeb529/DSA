class Solution {
public:
    bool canReach(vector<int>& heights, int n,int bricks, int ladders,int targetIndex){
        vector<int> heightDiff;
        long long totalPositiveDiff=0;
        for(int i=1;i<=targetIndex;i++){
            long long diff=heights[i]-heights[i-1];
            if(diff>0){
                heightDiff.push_back(diff);
                totalPositiveDiff+=diff;
            }
        }
        long long heightCoveredByLadder=0;
        sort(heightDiff.begin(),heightDiff.end(),greater<int>());
        for(int i=0;i<ladders&&i<heightDiff.size();i++){
            heightCoveredByLadder+=heightDiff[i];
        }
        if(totalPositiveDiff-heightCoveredByLadder<=bricks)return true;
        else return false;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int low=0,high=n-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canReach(heights,n,bricks,ladders,mid)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};