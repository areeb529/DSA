// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            if(M[x][y]==1&&M[y][x]==0){
                st.push(y);
            }
            if(M[y][x]==1&&M[x][y]==0){
                st.push(x);
            }
        }
        if(st.empty())return -1;
        else{
            int x=st.top(),y=st.top();
            bool f=true;
            for(int j=0;j<n;j++){
                if(M[x][j]==1)return -1;
            }
            for(int i=0;i<n;i++){
                if(i==y)continue;
                if(M[i][y]==0)return -1;
            }
            return x;
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends