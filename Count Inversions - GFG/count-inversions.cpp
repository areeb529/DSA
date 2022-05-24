// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

long long int merge(long long arr[], long long s,long long e,long long mid){
    vector<long long> temp(e-s+1);
    long long int inv=0;
    long long int i=s,j=mid+1;
    long long int k=0;
    while(i<=mid&&j<=e){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            inv+=(mid-i+1);
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    for(int k=0;k<temp.size();k++){
        arr[s+k]=temp[k];
    }
    return inv;
}
long long int mergeSort(long long arr[], long long s,long long e){
    if(s>=e){
        return 0;
    }
    long long int inv=0;
    long long mid=(e-s)/2+s;
    inv+=mergeSort(arr,s,mid);
    inv+=mergeSort(arr,mid+1,e);
    inv+=merge(arr,s,e,mid);
    return inv;
}
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long inv=mergeSort(arr,0,N-1);
        return inv;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends