// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    class triplet{
      public:
      int first;
      int second;
      int third;
    };
    static bool compare(const triplet &a,const triplet &b){
        return a.second<b.second||(a.second==b.second&&a.third<b.third);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<triplet> nums(n);
        for(int i=0;i<n;i++){
            nums[i]={start[i],end[i],i};
        }
        sort(nums.begin(),nums.end(),compare);
        int endTime=INT_MIN;
        int ans=0;
        for(auto &i:nums){
            if(endTime<i.first){
                ans++;
                endTime=i.second;
            }
        }
        return ans;
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