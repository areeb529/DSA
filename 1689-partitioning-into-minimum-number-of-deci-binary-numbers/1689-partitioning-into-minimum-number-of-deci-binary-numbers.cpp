class Solution {
public:
    int minPartitions(string n) {
        int maxDigit=0;
        for(auto &i:n){
            maxDigit=max(maxDigit,i-'0');
        }
        return maxDigit;
    }
};