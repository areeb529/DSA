class Solution {
public:
    // void getNextSmallerToRight(stack<int> &st,vector<int>& nums,int n,vector<int> &nseToRight){
    //     for(int i=n-1;i>=0;i--){
    //         while(!st.empty()&&nums[i]<=nums[st.top()]){
    //             st.pop();
    //         }
    //         if(!st.empty()){
    //             nseToRight[i]=st.top();
    //         }
    //         st.push(i);
    //     }
    // }
    // void getNextSmallerToLeft(stack<int> &st,vector<int>& nums,int n,vector<int> &nseToLeft){
    //     for(int i=0;i<n;i++){
    //         while(!st.empty()&&nums[i]<=nums[st.top()]){
    //             st.pop();
    //         }
    //         if(!st.empty()){
    //             nseToLeft[i]=st.top();
    //         }
    //         st.push(i);
    //     }
    // }
    int largestRectangleArea(vector<int>& heights) {
        // int n=heights.size();
        // stack<int> st;
        // vector<int> nseToLeft(n,-1);
        // vector<int> nseToRight(n,n);
        // getNextSmallerToLeft(st,heights,n,nseToLeft);
        // while(!st.empty()){
        //     st.pop();
        // }
        // getNextSmallerToRight(st,heights,n,nseToRight);
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,(nseToRight[i]-nseToLeft[i]-1)*heights[i]);
        // }
        // return ans;
        int n=heights.size();
        stack<int> st;
        int maxArea=0;
        int left=-1;
        for(int i=0;i<=n;i++){
            int right=i;
            while(!st.empty()&&(i==n||heights[i]<=heights[st.top()])){
                int height=heights[st.top()];
                left=-1;
                st.pop();
                if(!st.empty()){
                    left=st.top();
                }
                int area=(right-left-1)*height;
                maxArea=max(area,maxArea);
            }
            st.push(i);
        }
        return maxArea;
        
    }
};