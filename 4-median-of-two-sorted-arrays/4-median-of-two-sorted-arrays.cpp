class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())return findMedianSortedArrays(nums2,nums1);
        int m=nums1.size(),n=nums2.size();
        int low=0,high=m;
        double ans=-1;
        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=(m+n+1)/2-cut1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(cut1>0)
            l1=nums1[cut1-1];
            if(cut2>0)
            l2=nums2[cut2-1];
            if(cut1<m)
            r1=nums1[cut1];
            if(cut2<n)
            r2=nums2[cut2];
            if(l1>r2){
                high=cut1-1;
            }
            else if(l2>r1){
                low=cut1+1;
            }
            else{
                if((m+n)&1){
                    ans=max(l1,l2);
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