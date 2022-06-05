class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int k=(m+n)/2;
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        if(m==0){
            double ans;
            if(n&1){
                ans=nums2[k];
            }
            else{
                ans=(nums2[k-1]+nums2[k])/2.0;
            }
            return ans;
        }
        int low=max(0,k-n),high=min(k,m);
        double ans;
        while(low<=high){
            int cut1=(low+high)>>1;
            int cut2=k-cut1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(cut1>0)l1=nums1[cut1-1];
            if(cut2>0)l2=nums2[cut2-1];
            if(cut1<m)r1=nums1[cut1];
            if(cut2<n)r2=nums2[cut2];
            // cout<<"cut1 "<<cut1<<" "<<"cut2 "<<cut2<<endl;
            // cout<<"l1 "<<l1<<" "<<"l2 "<<l2<<" "<<"r1 "<<r1<<" "<<"r2 "<<r2<<endl;
            if(l1>r2){
                high=cut1-1;
            }
            else if(l2>r1){
                low=cut1+1;
            }
            else{
                if((m+n)&1){
                   ans=min(r1,r2); 
                }
                else{
                    ans=(max(l1,l2)+min(r1,r2))/2.0;
                }
                break;
            }
        }
        return ans;
    }
};