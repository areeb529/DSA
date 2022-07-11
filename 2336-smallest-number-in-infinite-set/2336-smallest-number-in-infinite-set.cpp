class SmallestInfiniteSet {
public:
    // priority_queue<int,vector<int>,greater<int>> pq;
    set<int> st;
    SmallestInfiniteSet() {
        int i=1;
        while(i<=1000){
            st.insert(i);
            i++;
        }
        
    }
    
    int popSmallest() {
        // if(pq.empty()){
        //     pq.push(2);
        //     return 1;
        // }
        // else{
        //     int ans=pq.top();
        //     pq.pop();
        //     if(pq.empty()){
        //         pq.push(ans+1);
        //     }
        //     return ans;
        // }
        auto it=st.begin();
        int ans= *it;
        st.erase(ans);
        return ans;
    }
    
    void addBack(int num) {
//         if(pq.empty()){
//             int i=1;
//             while(i<=num){
//                 pq.push(i);
//                 i++;
//             }
//         }
//         else{
            
//         }
        if(st.count(num)==0)st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */