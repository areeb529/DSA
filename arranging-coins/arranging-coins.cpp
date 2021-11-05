class Solution {
public:
    int arrangeCoins(int n) {
     long k=(-1+(long)sqrt(1+(long)8*n))/2;
     return (int)k;
    }
};