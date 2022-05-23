// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void helper(vector<int> &arr,int i,int n,int sum,vector<int> &res){
        if(i==n){
            res.push_back(sum);
            return;
        }
        helper(arr,i+1,n,sum+arr[i],res);
        helper(arr,i+1,n,sum,res);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int n=arr.size();
        int sum=0;
        vector<int> res;
        helper(arr,0,N,sum,res);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends