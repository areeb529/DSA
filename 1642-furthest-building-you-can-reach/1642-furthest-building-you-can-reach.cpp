class Solution {
public:
    // bool canReach(vector<int>& heights, int n,int bricks, int ladders,int targetIndex){
    //     vector<int> heightDiff;
    //     long long totalPositiveDiff=0;
    //     for(int i=1;i<=targetIndex;i++){
    //         long long diff=heights[i]-heights[i-1];
    //         if(diff>0){
    //             heightDiff.push_back(diff);
    //             totalPositiveDiff+=diff;
    //         }
    //     }
    //     long long heightCoveredByLadder=0;
    //     sort(heightDiff.begin(),heightDiff.end(),greater<int>());
    //     for(int i=0;i<ladders&&i<heightDiff.size();i++){
    //         heightCoveredByLadder+=heightDiff[i];
    //     }
    //     if(totalPositiveDiff-heightCoveredByLadder<=bricks)return true;
    //     else return false;
    // }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        long long heightCoveredByLadder=0;
        long long totalPositiveDiff=0;
        int ans=n-1;
        for(int i=1;i<n;i++){
            long long diff=heights[i]-heights[i-1];
            if(diff>0){
                totalPositiveDiff+=diff;
                if(pq.size()<ladders){
                    pq.push(diff);
                    heightCoveredByLadder+=diff;
                }
                else{
                    if(!pq.empty()&&pq.top()<diff){
                        heightCoveredByLadder-=pq.top();
                        pq.pop();
                        pq.push(diff);
                        heightCoveredByLadder+=diff;
                    }
                }
                if(totalPositiveDiff-heightCoveredByLadder>bricks){
                    ans=i-1;
                    break;
                }
            }
        }
        return ans;
    }
};