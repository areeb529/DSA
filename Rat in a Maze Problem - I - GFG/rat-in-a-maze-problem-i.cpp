// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> res;
    bool canReach(vector<vector<int>> &m,int row,int col,int n){
        if(row<0||row>=n||col<0||col>=n||m[row][col]==0)return false;
        else return true;
    }
    void findPath(vector<vector<int>> &m,int row,int col,int n,string &s){
        if(row==n-1&&col==n-1){
            res.push_back(s);
            return;
        }
        m[row][col]=0;
        vector<int> dx={-1,0,1,0,-1};
        string move="URDL";
        for(int i=0;i<dx.size()-1;i++){
            if(canReach(m,row+dx[i],col+dx[i+1],n)){
                s.push_back(move[i]);
                findPath(m,row+dx[i],col+dx[i+1],n,s);
                s.pop_back();
            }
        }
        m[row][col]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0||m[n-1][n-1]==0)return res;
        string s;
        findPath(m,0,0,n,s);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends