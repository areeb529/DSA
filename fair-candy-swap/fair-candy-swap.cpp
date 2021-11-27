class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long long sum1=0;
        long long sum2=0;
        unordered_set<int> st;
        for(int i=0;i<aliceSizes.size();i++){
            sum1+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.size();i++){
            sum2+=bobSizes[i];
            st.insert(bobSizes[i]);
        }
        long long diff=abs(sum1-sum2);
        vector<int> ans(2,0);
        for(int i=0;i<aliceSizes.size();i++){
            if(sum1>sum2){
                if(st.count(aliceSizes[i]-diff/2)==1){
                    ans[0]=aliceSizes[i];
                    ans[1]=aliceSizes[i]-diff/2;
                    break;
                }
            }
            else{
                if(st.count(aliceSizes[i]+diff/2)==1){
                    ans[0]=aliceSizes[i];
                    ans[1]=aliceSizes[i]+diff/2;
                    break;
                }
            }
        }
        return ans;
    }
};