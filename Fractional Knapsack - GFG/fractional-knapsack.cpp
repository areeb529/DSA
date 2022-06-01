// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(const pair<double,Item> &a,const pair<double,Item> &b){
        return a.first>b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,Item>> nums(n);
        double ans=0;
        for(int i=0;i<n;i++){
            nums[i]={(double)arr[i].value/arr[i].weight,arr[i]};
        }
        sort(nums.begin(),nums.end(),compare);
        //reverse(nums.begin(),nums.end());
        int wgt=W;
        
        for(int i=0;i<n&&wgt;i++){
            if(nums[i].second.weight<=wgt){
                wgt-=nums[i].second.weight;
                ans+=nums[i].second.value;
            }
            else{
                ans+=wgt*nums[i].first;
                wgt=0;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends