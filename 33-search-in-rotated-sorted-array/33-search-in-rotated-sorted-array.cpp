class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=-1;
        int low=0,high=n-1;
        while(low<=high){
            int mid=(high-low)/2+low;
            int comparator=nums[mid];
            if((nums[0]<=nums[mid])==(nums[0]<=target))comparator=nums[mid];
            else{
                if(nums[0]<=target)comparator=INT_MAX;
                else comparator=INT_MIN;
            }
            if(target<comparator)high=mid-1;
            else if(target>comparator)low=mid+1;
            else return mid;
        }
        return ans;
        
    }
};