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
 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+30,0);
        for(int i=n-1;i>=0;i--){
            int op1=costs[0]+dp[upperB(days,i,n-1,days[i]+1)];
            int op2=costs[1]+dp[upperB(days,i,n-1,days[i]+7)];
            int op3=costs[2]+dp[upperB(days,i,n-1,days[i]+30)];
            dp[i]=min(op1,min(op2,op3));
        }
        return dp[0];
    }
};