// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> nums(n);
        for(int i=0;i<n;i++){
            nums[i]={start[i],end[i]};
        }
        sort(nums.begin(),nums.end());
        int res=1;
        pair<int,int> p=nums[0];
        for(auto &i:nums){
            if(i.first<=p.second){
                if(i.second<=p.second){
                    p=i;
                }
            }
            else{
                p=i;
                res++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends