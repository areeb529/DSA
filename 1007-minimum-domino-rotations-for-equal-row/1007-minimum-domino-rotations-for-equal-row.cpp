class Solution {
public:
    int helper(vector<int>& tops, vector<int>& bottoms,int diceValue,int n){
        int topEqualValueRotations=0;
        for(int i=0;i<n;i++){
            if(tops[i]!=diceValue)topEqualValueRotations++;
        }
        int bottomEqualValueRotations=0;
        for(int i=0;i<n;i++){
            if(bottoms[i]!=diceValue)bottomEqualValueRotations++;
        }
        return min(topEqualValueRotations,bottomEqualValueRotations);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        //vector<int> freq={0,0,0,0,0,0,0};
        vector<int> freq(7,0);
        vector<int> equalRowValue;
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                freq[tops[i]]++;
                if(freq[tops[i]]==n)equalRowValue.push_back(tops[i]);
            }
            else{
                freq[tops[i]]++;
                if(freq[tops[i]]==n)equalRowValue.push_back(tops[i]);
                freq[bottoms[i]]++;
                if(freq[bottoms[i]]==n)equalRowValue.push_back(bottoms[i]);
            }
        }
        if(equalRowValue.size()==0)return -1;
        int ans=INT_MAX;
        for(int i=0;i<equalRowValue.size();i++){
            ans=min(ans,helper(tops,bottoms,equalRowValue[i],n));
        }
        return ans;
    }
};