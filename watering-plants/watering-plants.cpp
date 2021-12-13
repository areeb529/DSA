class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int currCapacity=capacity;
        int steps=0;
        for(int i=0;i<n;i++){
            if(currCapacity-plants[i]>=0){
                currCapacity-=plants[i];
                steps++;
            }
            else{
                currCapacity=capacity;
                steps=steps+i+i+1;
                currCapacity-=plants[i];
            }
        }
        return steps;
    }
};