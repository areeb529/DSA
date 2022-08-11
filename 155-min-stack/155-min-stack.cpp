class MinStack {
public:
    stack<pair<int,int>> st;
    int minM;
    MinStack() {
        minM=INT_MAX;
    }
    
    void push(int val) {
        minM=min(minM,val);
        st.push({val,minM});
    }
    
    void pop() {
        st.pop();
        if(!st.empty())minM=st.top().second;
        else minM=INT_MAX;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */