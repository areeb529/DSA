// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
        // int gap=(m+n)/2;
        //  while(gap){
        //     for(int i=0;i+gap<(m+n);i++){
        //         if(i<n&&i+gap<n){
        //             if(arr1[i]>arr1[i+gap])swap(arr1[i],arr1[i]);
        //         }
        //         else if(i<n&&i+gap>=n&&i+gap<m+n){
        //             if(arr1[i]>arr2[(i+gap)-n])swap(arr1[i],arr2[(i+gap)-n]);
        //         }
        //         else if(i>=n&&i+gap<m+n){
        //             if(arr2[i-n]>arr2[(i+gap)-n])swap(arr2[i-n],arr2[(i+gap)-n]);
        //         }
        //     }
        //     if(gap==1)gap=0;
        //     else
        //     gap=(gap+1)/2;
        //     }
        int i=0,j=0,k=n-1;
        while(i<=k&&j<m){
            if(arr1[i]<arr2[j]){
             i++;   
            }
            else{
                swap(arr2[j++],arr1[k--]);
            }
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
    } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends