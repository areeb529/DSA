class Solution {
public:
    // int upBound(vector<int> nums,int i,int j,long key){
    //     int ans=j+1;
    //     while(i<=j){
    //         int mid=(j-i)/2+i;
    //         if(key>(long)2*nums[mid]){
    //             ans=mid;
    //             j=mid-1;
    //         }
    //         else{
    //             i=mid+1;
    //         }
    //     }
    //     return ans;
    // }
    void merge(vector<int>& nums,int s,int e,int mid,vector<int> &temp){
        int i=s,j=mid+1;
        int k=s;
        while(i<=mid&&j<=e){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=e){
            temp[k++]=nums[j++];
        }
        for(int k=s;k<=e;k++){
            nums[k]=temp[k];
        }
    }
    int mergeSort(vector<int>& nums,int s,int e,vector<int> &temp){
        if(s>=e){
            return 0;
        }
        int rvp=0;
        
        int mid=(e-s)/2+s;
        rvp+=mergeSort(nums,s,mid,temp);
        rvp+=mergeSort(nums,mid+1,e,temp);
        int i=s,j=mid+1;
        while(i<=mid){
            while(j<=e&&nums[i]>(long)2*nums[j])j++;
            rvp+=(j-(mid+1));
            i++;
        }
        merge(nums,s,e,mid,temp);
        return rvp; 
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        return mergeSort(nums,0,n-1,temp);
    }
};