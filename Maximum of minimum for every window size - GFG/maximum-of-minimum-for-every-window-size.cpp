// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        
        vector<int> res(n,0);
        vector<int> nextGreaterLeft(n,-1);
        vector<int> nextGreaterRight(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty())st.push(i);
            else{
                while(!st.empty()&&arr[i]<=arr[st.top()]){
                    st.pop();
                }
                if(!st.empty())
                nextGreaterRight[i]=st.top();
                st.push(i);
            }
        }
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            if(st.empty())st.push(i);
            else{
                while(!st.empty()&&arr[i]<=arr[st.top()]){
                    st.pop();
                }
                if(!st.empty())
                nextGreaterLeft[i]=st.top();
                st.push(i);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<nextGreaterRight[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<nextGreaterLeft[i]<<" ";
        // }
        //cout<<endl;
        for(int i=0;i<n;i++){
            int left=0,right=0;
            if(nextGreaterLeft[i]!=-1)left=i-nextGreaterLeft[i]-1;
            else left=i;
            if(nextGreaterRight[i]!=-1)right=nextGreaterRight[i]-i-1;
            else right=n-1-i;
            res[left+right]=max(res[left+right],arr[i]);
            //cout<<left<<" "<<right<<" "<<res[left+right]<<" ";
        }
        //cout<<endl;
        int maxM=0;
        for(int i=n-2;i>=0;i--){
            res[i]=max(res[i],res[i+1]);
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
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends