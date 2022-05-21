// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int duplicate;
        for(int i=0;i<n;i++){
            int idx=abs(arr[i])-1;
            if(arr[idx]<0){
                duplicate=idx+1;
                break;
            }
            else{
                arr[idx]=-arr[idx];
            }
        }
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(arr[i]);
        }
        int missing=((long)n*(n+1))/2-(sum-duplicate);
        int *ans=new int[2];
        ans[0]=duplicate;
        ans[1]=missing;
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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends