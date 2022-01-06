class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         vector<int> v(1001,0);
        int n=trips.size();
        for(int i=0;i<n;i++){
            v[trips[i][1]]-=trips[i][0];
            v[trips[i][2]]+=trips[i][0];
        }
        int currCapacity=capacity;
        for(int i=0;i<=1000;i++){
            currCapacity+=v[i];
            if(currCapacity<0)return false;
        }
        return true;
        
    }
};