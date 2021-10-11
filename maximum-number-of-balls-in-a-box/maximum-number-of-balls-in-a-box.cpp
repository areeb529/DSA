class Solution {
public:
    int sumDigits(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> mp;
            int maxB=0;
        for(int i=lowLimit;i<=highLimit;i++){
            int sum=sumDigits(i);
            mp[sum]++;
            maxB=max(maxB,mp[sum]);
        }
        return maxB;
    }
};