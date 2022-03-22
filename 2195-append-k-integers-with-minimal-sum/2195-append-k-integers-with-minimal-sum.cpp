class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // long long res=0;
        // for(int i=0;i<n&&k;i++){
        //     long long diff;
        //     if(i==0){
        //         diff=nums[i]-1;
        //         k-=diff;
        //         res+=(long)diff*(diff+1)/2;
        //         cout<<k<<":"<<res<<" ";
        //     }
        //     else{
        //         diff=(nums[i]-nums[i-1]-1);
        //         if(diff<=k){
        //         k-=diff;
        //         res+=((long)nums[i]*(nums[i]+1)/2-(long)nums[i-1]*(nums[i-1]+1)/2-nums[i]);
        //             cout<<k<<":"<<res<<" ";
        //         }
        //         else{
        //             res+=((long)(nums[i-1]+k)*(nums[i-1]+k+1)/2-(long)nums[i-1]*(nums[i-1]+1)/2-nums[i-1]-k);
        //             cout<<k<<":"<<res<<" ";
        //             k=0;
        //         }
        //     }
        // }
        // if(k){
        //     res+=((long)(nums[n-1]+k)*(nums[n-1]+k+1)/2-(long)nums[n-1]*(nums[n-1]+1)/2);
        //     cout<<k<<":"<<res<<" ";
        // }
        // cout<<endl;
        // return res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n&&k;i++){
            long long diff;
            if(i==0){
                diff=nums[0]-1;
                if(diff>=k){
                    res=res+(long)k*(k+1)/2;
                    k=0;
                }
                else{
                    res=res+diff*(diff+1)/2;
                    k-=diff;
                }
                
            }
            else{
                diff=nums[i]-nums[i-1]-1;
                if(diff<=k&&diff!=-1){
                    k-=diff;
                    res=res+(long)nums[i]*(nums[i]+1)/2-(long)nums[i-1]*(nums[i-1]+1)/2-nums[i];
                }
                else{
                    if(diff!=-1){
                        res=res+(long)(nums[i-1]+k)*(nums[i-1]+k+1)/2-(long)nums[i-1]*(nums[i-1]+1)/2;
                        k=0;
                    }
                }
            }
            
        }
        if(k){
            res=res+(long)(nums[n-1]+k)*(nums[n-1]+k+1)/2-(long)(nums[n-1])*(nums[n-1]+1)/2;
        }
        return res;
    }
};