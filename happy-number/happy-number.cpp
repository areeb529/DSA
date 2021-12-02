class Solution {
public:
    int sumDigits(int n){
        int sum=0;
        while(n){
            int k=n%10;
            sum+=k*k;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!=1){
            n=sumDigits(n);
            if(st.count(n)==0)st.insert(n);
            else return false;
        }
        return true;
    }
};