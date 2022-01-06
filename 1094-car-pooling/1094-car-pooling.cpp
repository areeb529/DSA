class Solution {
public:
    static bool compare(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1]||a[1]==b[1]&&a[2]<b[2]||a[1]==b[1]&&a[2]==b[2]&&a[0]<b[0];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),compare);
        int currCapacity=capacity;
        int n=trips.size();

        vector<int> v(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[j]){
                    if(trips[j][2]<=trips[i][1]){
                        v[j]=0;
                        currCapacity+=trips[j][0];
                    }
                }
            }
            currCapacity-=trips[i][0];
            if(currCapacity<0)return false;
        }
        return true;
        
    }
};