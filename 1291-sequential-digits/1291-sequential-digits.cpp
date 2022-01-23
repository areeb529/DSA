class Solution {
public:
    int countDigits(int num){
        int k=0;
        while(num){
            k++;
            num/=10;
        }
        return k;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int m=countDigits(low);
        int n=countDigits(high);
        vector<int> v(9);
        for(int i=0;i<9;i++){
            v[i]=i+1;
        }
        bool f=false;
        for(int k=m;k<=n;k++){
            for(int i=0;i+k-1<9;i++){
                int num=0;
                for(int j=i;j<i+k;j++){
                    num=num*10+v[j];
                }
                if(low<=num&&num<=high){
                    ans.push_back(num);
                }
                if(num>high){
                    f=true;
                    break;
                }
            }
            if(f)break;
        }
        return ans;
    }
};