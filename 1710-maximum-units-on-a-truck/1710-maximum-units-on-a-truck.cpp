class Solution {
public:
    static bool compare(const vector<int> &a,const vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans=0;
        for(auto i:boxTypes){
            if(truckSize>=i[0]){
                truckSize-=i[0];
                ans+=i[0]*i[1];
            }
            else{
                ans+=i[1]*truckSize;
                break;
            }
        }
        return ans;
    }
};