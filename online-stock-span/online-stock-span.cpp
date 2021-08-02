class StockSpanner {
public:
    vector<int> v;
    stack<int> s;
    //unordered_map<int> mp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        if(s.empty()){
            s.push(v.size()-1);
            return 1;
        }
        else if(price<v[s.top()]){
            s.push(v.size()-1);
            return 1;
        }
        else if(price>=v[s.top()]){
            while(!s.empty()&&price>=v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                s.push(v.size()-1);
                return v.size();
            }
            else{
                int temp=s.top();
                s.push(v.size()-1);
                return v.size()-1-temp;
            }
        }
        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */