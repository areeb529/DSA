class Solution {
public:
    int candy(vector<int>& ratings) {
        //int n=ratings.size();
        // vector<int> candies(n,1);
        // for(int i=0;i<n;i++){
        //     int leftCandies=0,rightCandies=0;
        //     if(i-1>=0&&ratings[i-1]<ratings[i]){
        //         candies[i]=candies[i-1]+1;
        //     }
        //     if(i+1<n&&ratings[i]>ratings[i+1]){
        //         if(candies[i]<=candies[i+1]){
        //             candies[i]=candies[i+1]+1;
        //         }
        //     }
        // }
        // int res=0;
        // for(int i=0;i<n;i++){
        //     cout<<candies[i]<<" ";
        //     res+=candies[i];
        // }
        // cout<<endl;
        // return res;
        int n=ratings.size();
        vector<int> inc(n,1);
        vector<int> dec(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])inc[i]=inc[i-1]+1;
            if(ratings[n-i-1]>ratings[n-i])dec[n-i-1]=dec[n-i]+1;
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=max(inc[i],dec[i]);
        }
        return res; 
        
    }
};