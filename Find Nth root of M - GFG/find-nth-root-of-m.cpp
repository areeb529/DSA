// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int s=0,e=m;
	    if(m==1)return 1;
	    if(n==1)return m;
	    int ans=-1;
	    long target=m;
	    while(s<=e){
	        long mid=(e-s)/2+s;
	       // cout<<"s "<<s<<" "<<"e "<<e<<endl;
	       // cout<<"mid "<<mid<<endl;
	        long x=1;
	        int i=0;
	        bool f=false;
	        while(i<n){
	            x*=mid;
	            if(x>INT_MAX){
	                e=mid-1;
	                f=true;
	                break;
	            }
	            i++;
	        }
	        if(f)continue;
	        //cout<<"x "<<x<<endl;
	        if(x==target){
	            ans=mid;
	            break;
	        }
	        else if(x<target){
	            s=mid+1;
	        }
	        else{
	            e=mid-1;
	        }
	        
	    }
	    return ans;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends