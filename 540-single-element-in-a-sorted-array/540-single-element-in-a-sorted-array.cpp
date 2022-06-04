class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int s=0,e=n-1;
        int ans=-1;
        while(s<=e){
            int mid=(e-s)/2+s;
            //cout<<"s "<<s<<" "<<"e "<<e<<"mid "<<mid<<endl;
            if(mid-1>=0&&nums[mid-1]==nums[mid]){
                if((mid-1)%2==0){
                    s=mid+1;
                }
                else{
                    e=mid-2;
                }
            }
            else if(mid+1<n&&nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    s=mid+2;
                }
                else{
                    e=mid-1;
                }
            }
            else{
                ans=nums[mid];
                break;
            }
        }
        return ans;
    }
};