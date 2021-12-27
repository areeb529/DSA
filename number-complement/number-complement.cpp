class Solution {
public:
    int findComplement(int num) {
        if(num==1||num==0)return num^1;
        vector<int> nums;
        while(num){
            nums.push_back(num%2);
            num=num/2;
        }
        long p=1;
        long sum=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]^1;
            sum+=p*nums[i];
            p*=2;
        }
        return sum;
    }
};