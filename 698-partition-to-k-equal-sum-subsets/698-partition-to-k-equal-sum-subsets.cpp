class Solution {
public:
    bool partition(vector<int>& nums,int i,int n,int curSum,int targetSum,int k,vector<bool> &visited){
        if(k==0)return true;
        if(curSum==targetSum){
            return partition(nums,0,n,0,targetSum,k-1,visited);
        }
        else{
            for(int j=i;j<n;j++){
                if(!visited[j]&&(curSum+nums[j]<=targetSum)){
                    visited[j]=true;
                    if(partition(nums,j+1,n,curSum+nums[j],targetSum,k,visited)==true)return true;
                    visited[j]=false;
                    if(curSum==0)break;
                }
            }
            return false;
        }
        
    }
    // bool helper(vector<int>& nums,int i,int k,int curSum,int target,int n){
    //     if(i==n){
    //         if(curSum==target){
    //             k--;
    //             i=0;
    //         }
    //         else return false;
    //     }
    //     if(k==1)return true;
    //     if(nums[i]<0){
    //         return helper(nums,i+1,k,curSum,target,n);
    //     }
    //     else{
    //         bool op1=false,op2=false;
    //         if(curSum+nums[i]<=target){
    //             nums[i]=-nums[i];
    //             op1=helper(nums,i+1,k,curSum+nums[i],target,n);  
    //             nums[i]=-nums[i];
    //         }
    //         op2=helper(nums,i+1,k,curSum,target,n);
    //         bool res=op1||op2;
    //         return res;
    //     }
    // }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool> visited(n,false);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        //sort(nums.begin(),nums.end(),greater<int>());
        if(k==1)return true;
        if(sum%k!=0)return false;
        int kSum=sum/k;
        return partition(nums,0,n,0,kSum,k,visited);
       //  int n=nums.size();
       //  int sum=0;
       //  for(int i=0;i<n;i++){
       //      sum+=nums[i];
       //  }
       //  if(k==1)return true;
       //  if(sum%k!=0)return false;
       // return helper(nums,0,k,0,sum/k,n);
        
        
    }
};