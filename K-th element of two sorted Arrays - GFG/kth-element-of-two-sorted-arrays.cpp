// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int helper(int arr1[],int arr2[],int n,int m,int k){
        int low=max(0,k-m),high=min(n,k);
        while(low<=high){
            int cut1=(low+high)>>1;
            int cut2=k-cut1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(cut1>0)l1=arr1[cut1-1];
            if(cut2>0)l2=arr2[cut2-1];
            if(cut1<n)r1=arr1[cut1];
            if(cut2<m)r2=arr2[cut2];

            if(l1>r2){
                high=cut1-1;
            }
            else if(l2>r1){
                low=cut1+1;
            }
            else{
                return max(l1,l2);
            }
        }
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n<=m){
            return helper(arr1,arr2,n,m,k);
        }
        else{
            return helper(arr2,arr1,m,n,k);
        }
        
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends