class Solution {
public:
    int upperB(vector<int>& days,int i,int j,int key){
        int ans=days.size();
        while(i<=j){
            int mid=(i+j)/2;
            if(days[mid]==key){
                ans=mid;
                return ans;
            }
            else if(days[mid]>key){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
    int minCost(vector<int>& days,int i,vector<int>& costs,int n,vector<int> &dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int op1=costs[0]+minCost(days,upperB(days,i,n-1,days[i]+1),costs,n,dp);
        int op2=costs[1]+minCost(days,upperB(days,i,n-1,days[i]+7),costs,n,dp);
        int op3=costs[2]+minCost(days,upperB(days,i,n-1,days[i]+30),costs,n,dp);
        return dp[i]=min(op1,min(op2,op3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,-1);
        return minCost(days,0,costs,n,dp);
    }
};