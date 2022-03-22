class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         long long res=0;
//         for(int i=0;i<n&&k;i++){
//             long long diff;
//             if(i==0){
//                 diff=nums[0]-1;
//                 if(diff>=k){
//                     res=res+(long)k*(k+1)/2;
//                     k=0;
//                 }
//                 else{
//                     res=res+diff*(diff+1)/2;
//                     k-=diff;
//                 }
                
//             }
//             else{
//                 diff=nums[i]-nums[i-1]-1;
//                 if(diff<=k&&diff!=-1){
//                     k-=diff;
//                     res=res+(long)nums[i]*(nums[i]+1)/2-(long)nums[i-1]*(nums[i-1]+1)/2-nums[i];
//                 }
//                 else{
//                     if(diff!=-1){
//                         res=res+(long)(nums[i-1]+k)*(nums[i-1]+k+1)/2-(long)nums[i-1]*(nums[i-1]+1)/2;
//                         k=0;
//                     }
//                 }
//             }
            
//         }
//         if(k){
//             res=res+(long)(nums[n-1]+k)*(nums[n-1]+k+1)/2-(long)(nums[n-1])*(nums[n-1]+1)/2;
//         }
//         return res;
        set<int> s(nums.begin(),nums.end());
        long long ans=(long)k*(k+1)/2;
        for(auto &i:s){
            if(i<=k){
                ans+=k+1;
                ans-=i;
                k++;
            }
            else break;
        }
        return ans;
        
    }
};