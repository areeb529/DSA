class Solution {
public:
    static bool compare(const pair<int,int> &a,const pair<int,int> &b){
        return (a.first<b.first)||(a.first==b.first&&a.second<b.second);
    }
    int lowerB(vector<pair<int,int>> &nums,int k,int key,int n){
        int i=k,j=n-1;
        int ans=k;
        while(i<=j){
            int mid=(j-i)/2+i;
            if(nums[mid].first<=key){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
        
    }
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n=tiles.size();
        vector<pair<int,int>> nums(n);
        vector<long> pre(n,0);
        for(int i=0;i<n;i++){
            nums[i]={tiles[i][0],tiles[i][1]};
        }
        sort(nums.begin(),nums.end(),compare);
        for(int i=0;i<n;i++){
            if(i>0){
                pre[i]=pre[i-1]+nums[i-1].second-nums[i-1].first+1;
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            int idx=lowerB(nums,i,nums[i].first+carpetLen-1,n);
            int sum1=pre[idx]-pre[i];
            if(nums[idx].second-nums[idx].first+1<carpetLen-(nums[idx].first-nums[i].first)){
                res=max(res,sum1+nums[idx].second-nums[idx].first+1);
            }
            else{
                res=max(res,sum1+carpetLen-(nums[idx].first-nums[i].first));
            }
        }
        return res;
        
    }
};