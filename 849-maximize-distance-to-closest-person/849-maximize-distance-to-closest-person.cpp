class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int dist=0;
        int maxDist=0;
        bool f=false;
        for(int i=0;i<n;i++){
            if(!seats[i]){
                if(i==0||i==n-1)f=true;
                dist++;
                if(!f)
                maxDist=max(dist,maxDist);
                else maxDist=max(dist*2,maxDist);
            }
            else{
                f=false;
                dist=0;
            }
        }
        return (maxDist-1)/2+1;
    }
};