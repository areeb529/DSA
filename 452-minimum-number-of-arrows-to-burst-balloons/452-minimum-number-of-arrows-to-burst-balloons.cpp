class Solution {
public:
    static bool compare(const vector<int> &a,const vector<int> &b){
        return a[0]<b[0]||a[0]==b[0]&&a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int n=points.size();
        if(n==1)return 1;
        int ct=0;
        int i=0;
        while(i<n){
            if(i<n-1&&points[i][1]>=points[i+1][0]){
                int rb=min(points[i][1],points[i+1][1]);
                i+=2;
                while(i<n&&points[i][0]<=rb){
                    rb=min(rb,points[i][1]);
                    i++;
                }
                ct++;
            }
            else{
                ct++;
                i++;
            }
        }
        return ct;
        
    }
};