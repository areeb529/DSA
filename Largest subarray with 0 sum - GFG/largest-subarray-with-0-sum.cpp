// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+A[i];
        }
        int maxM=0;
        unordered_map<int,int> mp;
        for(int i=n;i>=1;i--){
            mp[pre[i]]=i;
        }
        for(int i=1;i<=n;i++){
            if(pre[i])
            maxM=max(maxM,i-mp[pre[i]]);
            else maxM=max(maxM,i);
        }
        return maxM;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends