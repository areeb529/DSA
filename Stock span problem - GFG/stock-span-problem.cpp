// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    void getNextGreaterToLeft(stack<int> &st,int price[],int n,vector<int> &ngeToLeft){
        for(int i=0;i<n;i++){
            while(!st.empty()&&price[i]>=price[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ngeToLeft[i]=st.top();
            }
            st.push(i);
        }
    }
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> st;
       vector<int> ngeToLeft(n,-1);
       getNextGreaterToLeft(st,price,n,ngeToLeft);
       
       vector<int> res(n,1);
       for(int i=0;i<n;i++){
           res[i]=(i-ngeToLeft[i]);
       }
       return res;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends