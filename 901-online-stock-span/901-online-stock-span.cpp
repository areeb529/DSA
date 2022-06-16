class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        // if(st.empty()){
        //     st.push({price,1});
        //     return 1;
        // }
        // else{
        //     if(st.top().first<=price){
        //         st.push({price,st.top().second+1});
        //         return st.top().second;
        //     }
        //     else{
        //         st.push({price,1});
        //         return 1;
        //     }
        // }
        int cnt=1;
        while(!st.empty()&&price>=st.top().first){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt});
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */