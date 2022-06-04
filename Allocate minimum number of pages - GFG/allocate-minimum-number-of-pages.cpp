// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool allocations(int A[],long long mid,int n, int B){
    long long sum=0;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(sum+A[i]>mid){
            cnt++;
            if(cnt>B)return false;
            sum=0;
        }
        sum+=A[i];
    }
    return true;
}
    int findPages(int A[], int N, int M) 
    {
        //code here
        int n=N;
        int B=M;
    long long sum=0;
    int maxM=A[0];
    if(n<B)return -1;
    for(int i=0;i<n;i++){
        sum+=A[i];
        maxM=max(maxM,A[i]);
    }
    long long low=maxM,high=sum;
    int ans=-1;
    while(low<=high){
        long long mid=((high-low)>>1)+low;
        bool temp=allocations(A,mid,n,M);
        if(temp){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends